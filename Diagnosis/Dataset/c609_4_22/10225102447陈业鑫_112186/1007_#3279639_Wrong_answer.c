#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100005
#define MAXB 35
#define case_template "case #%d:\n"

int bit_count(int x) {
    int cnt = 0;
    while (x) {
        ++cnt;
        x &= x -1;
    }
    return cnt;
}

int cmp(const void *a, const void *b) {
    int bit_a = bit_count(*(int *)a);
    int bit_b = bit_count(*(int *)b);
    if (bit_a != bit_b) {
        return bit_b - bit_a;
    } else {
        return *(int *)a - *(int *)b;
    }
}

int main() {
    int T, t = 0;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int nums[MAXN];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &nums[i]);
        }
        qsort(nums, n, sizeof(int), cmp);
        printf(case_template" ", ++t);
        for (int i = 0; i < n; ++i) {
            printf("%d", nums[i]);
            if (i != n - 1) {
                putchar(' ');
            }
        }
        putchar('\n');
    }
    return 0;
}