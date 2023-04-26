#include <stdio.h>
#include<string.h>

int length[] = {0, 4, 7, 10};

int main() {
    char s[512];
    scanf("%s", s);
    int n = strlen(s);
    printf("0001");
    for (int i = 9; ~i; i--) {
        putchar((n >> i & 1) + '0');
    }
    for (int i = 0; i < n; i += 3) {
        int current = 0, len;
        for (int j = 0; j < 3 && i + j < n; j++) {
            current = current * 10 + s[i + j] - '0';
            len = length[j + 1];
        }
        for (int i = len - 1; ~i; i--) {
            putchar((current >> i & 1) + '0');
        }
    }
    putchar('\n');
}