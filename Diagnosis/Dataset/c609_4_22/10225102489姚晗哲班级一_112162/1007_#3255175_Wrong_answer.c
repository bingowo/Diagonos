#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int bitcount(int64_t x) {
    int count = 0;
    while (x) {
        count++;
        x &= x-1;
    }
    return count;
}

int cmp(const void* a, const void* b) {
    int64_t x = *(int64_t*)a;
    int64_t y = *(int64_t*)b;
    int count_x = bitcount(x);
    int count_y = bitcount(y);
    if (count_x != count_y) {
        return count_y - count_x;
    } else {
        return x - y;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int64_t nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &nums[i]);
    }
    qsort(nums, n, sizeof(int64_t), cmp);
    for (int i = 0; i < n; i++) {
        printf("%lld ", nums[i]);
    }
    printf("\n");
    return 0;
}
