#include <stdio.h>
#include <string.h>
#include <ctype.h>

int strnumcmp(const char* s1, const char* s2) {
    const int len1 = strlen(s1);
    const int len2 = strlen(s2);
    int i = 0, j = 0;
    while (i < len1 && j < len2) {
        if (isdigit(s1[i]) && isdigit(s2[j])) {
            long num1 = 0, num2 = 0;
            while (i < len1 && isdigit(s1[i])) {
                num1 = num1 * 10 + s1[i++] - '0';
            }
            while (j < len2 && isdigit(s2[j])) {
                num2 = num2 * 10 + s2[j++] - '0';
            }
            if (num1 < num2) {
                return -1;
            } else if (num1 > num2) {
                return 1;
            }
            continue;
        }
        if (s1[i] < s2[j]) {
            return -1;
        } else if (s1[i] > s2[j]) {
            return 1;
        }
        ++i;
        ++j;
    }
    if (i == len1 && j < len2) {
        return -1;
    } else if (i < len1 && j == len2) {
        return 1;
    }
    return 0;
}

int main() {
    const int max_n = 100000 + 5;
    char s[max_n][31];
    int n = 0;
    while (scanf("%s", s[n]) == 1) {
        ++n;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (strnumcmp(s[i], s[j]) > 0) {
                char temp[31];
                strcpy(temp, s[i]);
                strcpy(s[i], s[j]);
                strcpy(s[j], temp);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%s", s[i]);
        if (i != n - 1) {
            putchar(' ');
        }
    }
    putchar('\n');
    return 0;
}