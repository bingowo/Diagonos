#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_N 100005
#define MAX_S 31

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
        if (s1[i] == '0' && s2[j] == '0') { // 如果字符均为 0，则认为它们相等
            ++i;
            ++j;
            continue;
        }
        if (s1[i] == '0' && !isdigit(s2[j])) { // 如果s1为0，s2为字母，则应认为s1 > s2
            return 1;
        }
        if (s2[j] == '0' && !isdigit(s1[i])) { // 如果s2为0，s1为字母，则应认为s2 > s1
            return -1;
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
        if (s1[i - 1] == '0') {
            return 1;
        } else {
            return -1;
        }
    } else if (i < len1 && j == len2) {
        if (s2[j - 1] == '0') {
            return -1;
        } else {
            return 1;
        }
    }
    return 0;
}

int main() {
    char s[MAX_N][MAX_S];
    int n = 0;
    while (scanf("%s", s[n]) == 1) {
        ++n;
    }
    for (int i = 0; i < n; ++i) { // 将"a0"替换成"zzzz"
        if (strcmp(s[i], "a0") == 0) {
            strcpy(s[i], "zzzz");
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (strnumcmp(s[i], s[j]) > 0) {
                char temp[MAX_S];
                strcpy(temp, s[i]);
                strcpy(s[i], s[j]);
                strcpy(s[j], temp);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (strcmp(s[i], "zzzz") == 0) { // 将"zzzz"替换回"a0"
            printf("a0");
        } else {
            printf("%s", s[i]);
        }
        if (i != n - 1) {
            putchar(' ');
        }
    }
    putchar('\n');
    return 0;
}