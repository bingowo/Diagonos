#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 1005
#define MAX_L 105

int n;

// 比较函数直接以字符串的形式比较两个数字
int cmp(const void* _a, const void* _b) {
    char* a = *(char**)_a;
    char* b = *(char**)_b;
    int len1 = strlen(a), len2 = strlen(b), i = 0, j = 0;
    if (a[0] == '-') {
        ++i;
    }
    if (b[0] == '-') {
        ++j;
    }
    if (len1 - i != len2 - j) {
        return len1 - len2; // 长度不同的，最高位长度更小的肯定在前
    }
    // 从高位到低位一位一位比较
    for (; i < len1 && j < len2; ++i, ++j) {
        if (a[i] != b[j]) {
            return a[i] - b[j];
        }
    }
    return 0;
}

int main() {
    char* str[MAX_N];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        str[i] = (char*)malloc(sizeof(char) * MAX_L);
        scanf("%s", str[i]);
    }
    // C库函数qsort进行排序
    qsort(str, n, sizeof(char*), cmp);
    for (int i = 0; i < n; ++i) {
        printf("%s\n", str[i]);
    }

    // 释放内存
    for (int i = 0; i < n; ++i) {
        free(str[i]);
    }
    return 0;
}