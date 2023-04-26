#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100000

// 将数字n转换成r进制字符串
char* convert(int n, int r) {
    char* digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* result = (char*) malloc(sizeof(char) * (MAX_LEN + 1));
    int index = 0;
    int is_negative = (n < 0);
    
    if (is_negative) {
        n = -n;
    }
    
    // 不断将n除以r，直到商为0
    do {
        result[index++] = digits[n % r];
        n /= r;
    } while (n != 0);
    
    if (is_negative) {
        result[index++] = '-';
    }
    
    result[index] = '\0';
    
    // 反转字符串
    int len = strlen(result);
    for (int i = 0; i < len / 2; i++) {
        char temp = result[i];
        result[i] = result[len - i - 1];
        result[len - i - 1] = temp;
    }
    
    return result;
}

int main() {
    int t;  // 测试数据组数
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        int n, r;  // n为十进制数，r为进制数
        scanf("%d %d", &n, &r);
        
        char* result = convert(n, r);
        printf("%s\n", result);
        free(result);
    }
    
    return 0;
}