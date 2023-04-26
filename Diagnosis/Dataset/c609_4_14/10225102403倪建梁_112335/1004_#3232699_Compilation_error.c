#include <stdio.h>
#include <string.h>

// 将字符 c 转换为对应的十进制数
int charToNum(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'a' && c <= 'z') {
        return c - 'a' + 10;
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    } else {
        return -1; // 非法字符
    }
}

// 将十进制数 num 转换为对应的字符
char numToChar(int num) {
    if (num >= 0 && num <= 9) {
        return num + '0';
    } else {
        return num - 10 + 'A';
    }
}

// 将 A 进制整数 n 转换为十进制数
int convertToDecimal(char n[], int A) {
    int len = strlen(n);
    int decimal = 0;
    int power = 1;
    for (int i = len - 1; i >= 0; i--) {
        int num = charToNum(n[i]);
        if (num == -1 || num >= A) {
            return -1; // 非法字符或越界
        }
        decimal += num * power;
        power *= A;
    }
    return decimal;
}

// 将十进制数 decimal 转换为 B 进制整数，保存到 result 数组中
void convertToBase(int decimal, int B, char result[]) {
    int i = 0;
    while (decimal > 0) {
        int remainder = decimal % B;
        result[i++] = numToChar(remainder);
        decimal /= B;
    }
    result[i] = '\0';
    strrev(result); // 反转字符串
}

int main() {
    char n[100],result[100];int A, B;
    scanf("%d %s %d",&A,n,&B);
    int decimal = convertToDecimal(n, A);
    if (decimal == -1) {
        printf("输入的 A 进制整数不合法。\n");
        return 0;
    }
    convertToBase(decimal, B, result);
    printf("%s\n",result);
    return 0;
}