#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void reverse(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

int char_to_digit(char c)
{
    if (isdigit(c)) {
        return c - '0';
    } else if (isupper(c)) {
        return c - 'A' + 10;
    } else {
        return -1; // 错误的字符
    }
}

int main()
{
    int A, B;
    char n_str[100];
    scanf("%d %s %d", &A, n_str, &B);

    // 将n转换为十进制
    int dec = 0;
    int base = 1;
    int len = strlen(n_str);
    for (int i = len - 1; i >= 0; i--) {
        int digit = char_to_digit(n_str[i]);
        if (digit < 0 || digit >= A) {
            printf("Error: the digit '%c' is not valid in base %d\n", n_str[i], A);
            return 1;
        }
        dec += digit * base;
        base *= A;
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