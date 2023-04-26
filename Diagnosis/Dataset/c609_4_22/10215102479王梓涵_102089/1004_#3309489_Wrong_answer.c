#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

int main()
{
    int A, n, B;
    scanf("%d %d %d", &A, &n, &B);

    // 将n转换为十进制
    int dec = 0;
    int base = 1;
    while (n > 0) {
        int digit = n % 10;
        if (digit >= A) {
            printf("Error: the digit %d is not valid in base %d\n", digit, A);
            return 1;
        }
        dec += digit * base;
        base *= A;
        n /= 10;
    }

    // 将十进制数转换为B进制
    char result[100];
    int index = 0;
    while (dec > 0) {
        int digit = dec % B;
        result[index++] = (digit < 10) ? digit + '0' : digit - 10 + 'A';
        dec /= B;
    }
    result[index] = '\0';

    // 输出结果
    reverse(result);
    printf("%s\n", result);

    return 0;
}
