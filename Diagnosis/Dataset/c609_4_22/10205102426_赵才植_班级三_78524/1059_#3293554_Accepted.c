#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100
#define MAX_DIGITS 105

// 比较两个字符串表示的数的大小，返回值为负数、0、正数分别表示第一个数小于、等于、大于第二个数
int cmp(const char* a, const char* b) {
    double x = atof(a);
    double y = atof(b);
    if (x < y) {
        return -1;
    } else if (x > y) {
        return 1;
    } else {
        return 0;
    }
}

// 快速排序
void qsort_str(char** a, int l, int r) {
    if (l >= r) {
        return;
    }
    int i = l, j = r;
    char* pivot = a[(l + r) / 2];
    while (i <= j) {
        while (cmp(a[i], pivot) < 0) {
            i++;
        }
        while (cmp(a[j], pivot) > 0) {
            j--;
        }
        if (i <= j) {
            char* temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    qsort_str(a, l, j);
    qsort_str(a, i, r);
}

int main() {
    int n;
    char* nums[MAX_N];
    char s[MAX_DIGITS];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        nums[i] = (char*)malloc(sizeof(char) * strlen(s) + 1);
        strcpy(nums[i], s);
    }
    qsort_str(nums, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%s\n", nums[i]);
        free(nums[i]);
    }
    return 0;
}
