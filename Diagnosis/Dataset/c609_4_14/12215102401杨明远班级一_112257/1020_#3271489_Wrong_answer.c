 #include <stdio.h>
#include <string.h>
#include <ctype.h>

int strnumcmp(const char* s1, const char* s2) {
    const int L1 = strlen(s1), L2 = strlen(s2);
    int i = 0, j = 0;
    while (i < L1 && j < L2) {
        if (isdigit(s1[i]) && isdigit(s2[j])) {
            int n1 = 0, n2 = 0;
            while (i < L1 && isdigit(s1[i])) n1 = n1 * 10 + (s1[i++] - '0');
            while (j < L2 && isdigit(s2[j])) n2 = n2 * 10 + (s2[j++] - '0');
            if (n1 != n2) return n1 - n2;
        } else if (s1[i] != s2[j]) {
            return s1[i] - s2[j];
        } else {
            ++i, ++j;
        }
    }
    if (i == L1 && j == L2) return 0;
    if (isdigit(s1[i-1])) return -1;
    return 1;
}

int main() {
    const int MAXN = 100;
    char str[MAXN][31];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", str[i]);
    }
    // 冒泡排序
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (strnumcmp(str[j], str[j+1]) > 0) {
                char tmp[31];
                strcpy(tmp, str[j]);
                strcpy(str[j], str[j+1]);
                strcpy(str[j+1], tmp);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%s ", str[i]);
    }
    return 0;
}
