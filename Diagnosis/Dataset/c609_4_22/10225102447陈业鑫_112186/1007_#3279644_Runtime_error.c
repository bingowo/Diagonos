#include <stdio.h>

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
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        int n;
        scanf("%d", &n);
        int *nums = (int *)malloc(sizeof(int) * n);
        int cnt = 0, sign;
        char c;
        while (n--) {
            cnt = 0;
            do {
                sign = 1;
                while ((c = getchar()) != '-' && (c < '0' || c > '9'));
                if (c == '-') {
                    sign = -1;
                    c = getchar();
                }
            } while (c < '0' || c > '9');
            while (c >= '0' && c <= '9') {
                cnt = cnt * 10 + c - '0';
                c = getchar();
            }
            nums[n] = cnt * sign;
        }
        qsort(nums, n, sizeof(int), cmp);
        printf("case #%d:", i);
        for (int j = 0; j < n; ++j) {
            printf(" %d", nums[j]);
        }
        putchar('\n');
        free(nums);
    }
    return 0;
}