#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 1005
#define MAX_L 105

int n;

// 辅助函数，用于比较两个字符串的大小
int compare(const char* a, const char* b) {
    // 跳过可能的符号位
    int a_len = strlen(a), b_len = strlen(b), a_start = 0, b_start = 0;
    if (a[0] == '+' || a[0] == '-') {
        ++a_start;
    }
    if (b[0] == '+' || b[0] == '-') {
        ++b_start;
    }
    // 比较两个数字的位数（含整数部分和小数部分）
    int a_cnt = 0, b_cnt = 0, a_dot = -1, b_dot = -1;
    for (int i = a_start; i < a_len; ++i) {
        if (a[i] == '.') {
            a_dot = i;
            break;
        }
        ++a_cnt;
    }
    for (int i = b_start; i < b_len; ++i) {
        if (b[i] == '.') {
            b_dot = i;
            break;
        }
        ++b_cnt;
    }
    // 如果两个数字不含小数部分，则按数字的位数从高到低一位一位比较
    if (a_dot == -1 && b_dot == -1) {
        if (a_cnt != b_cnt) {
            return a_cnt - b_cnt;
        }
        for (int i = 0; i < a_cnt; ++i) {
            if (a[i + a_start] != b[i + b_start]) {
                return a[i + a_start] - b[i + b_start];
            }
        }
        return 0;
    }
    // 如果两个数字都含小数部分，先比较整数部分的位数
    if (a_dot != -1 && b_dot != -1) {
        if (a_cnt != b_cnt) {
            return a_cnt - b_cnt;
        }
    } else {
        return (a_dot == -1 ? a_cnt : 0) - (b_dot == -1 ? b_cnt : 0);
    }
    // 整数部分位数相同的情况下，按数字大小从高到低一位一位比较
    int a_i = a_start, b_i = b_start;
    for (; a_i < a_dot && b_i < b_dot; ++a_i, ++b_i) {
        if (a[a_i] != b[b_i]) {
            return a[a_i] - b[b_i];
        }
    }
    // 如果一个数字已经比较结束，而另一个数字后面还有数字，则较长的数字更大
    if (a_i == a_dot && b_i < b_dot) {
        return -1;
    } else if (b_i == b_dot && a_i < a_dot) {
        return 1;
    }
    // 按小数部分的位数从低到高一位一位比较
    a_i = a_dot + 1, b_i = b_dot + 1;
    for (; a_i < a_len && b_i < b_len; ++a_i, ++b_i) {
        if (a[a_i] != b[b_i]) {
            return a[a_i] - b[b_i];
        }
    }
    // 如果一个数字已经比较结束，而另一个数字后面还有数字，则较长的数字更大
    if (a_i == a_len && b_i < b_len) {
        return 1;
    } else if (b_i == b_len && a_i < a_len) {
        return -1;
    }
    return 0;
}

// 用于 C 语言库函数 qsort() 的比较函数
int cmp(const void* p1, const void* p2) {
    return compare(*(const char**)p1, *(const char**)p2);
}

int main() {
    char* nums[MAX_N];
    for (int i = 0; i < MAX_N; ++i) {
        nums[i] = (char*)malloc(sizeof(char) * MAX_L);
    }
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
scanf("%s", nums[i]);
}
qsort(nums, n, sizeof(char*), cmp);
for (int i = 0; i < n; ++i) {
printf("%s\n", nums[i]);
}
for (int i = 0; i < MAX_N; ++i) {
free(nums[i]);
}
return 0;
}

