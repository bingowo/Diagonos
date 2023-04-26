#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 1005
#define MAX_L 105

int n;

int cmp(const void* _a, const void* _b) {
    char* a = *(char**)_a;
    char* b = *(char**)_b;
    int len1 = strlen(a), len2 = strlen(b);
    if (len1 != len2) {
        return len1 - len2;
    }
    return strcmp(a, b);
}

int main() {
    char* str[MAX_N];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        str[i] = (char*)malloc(sizeof(char) * MAX_L);
        scanf("%s", str[i]);
        if (str[i][0] == '+') { // 去掉正号
            memmove(str[i], str[i] + 1, sizeof(char) * strlen(str[i]));
        }
    }
    qsort(str, n, sizeof(char*), cmp);
    for (int i = 0; i < n; ++i) {
        printf("%s\n", str[i]);
    }
    return 0;
}