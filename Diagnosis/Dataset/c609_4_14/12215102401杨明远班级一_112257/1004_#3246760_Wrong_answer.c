#include <stdio.h>
#include <string.h>

char digitToChar(int digit) {
    if (digit >= 0 && digit <= 9) {
        return '0' + digit;
    }
    else {
        return 'A' + digit - 10;
    }
}

int charToDigit(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    else {
        return c - 'A' + 10;
    }
}

void reverseString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
}

int main() {
    int a, b;
    char n[1000];
    scanf("%d%s%d", &a, n, &b);

    int num = 0;
    int len = strlen(n);
    for (int i = 0; i < len; i++) {
        num = num * a + charToDigit(n[i]);
    }

    char res[33];
    int pos = 0;
    while (num) {
        int remainder = num % b;
        res[pos++] = digitToChar(remainder);
        num /= b;
    }
    if (pos == 0) {
        res[pos++] = '0';
    }
    res[pos] = '\0';

    reverseString(res);
    printf("%s", res);

    return 0;
}