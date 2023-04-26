#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000000

struct Number {
    int value;  // 原数值
    int digits;  // 位数
};

int getDigits(int x) {
    // 计算整数的位数
    int cnt = 0;
    while (x) {
        cnt++;
        x /= 10;
    }
    return cnt;
}

int cmp(const void *a, const void *b) {
    struct Number *pa = (struct Number *) a;
    struct Number *pb = (struct Number *) b;
    if (pa->digits != pb->digits) {
        // 按照位数从大到小排序
        return pb->digits - pa->digits;
    } else {
        // 如果位数相同，按照原数值从小到大排序
        return pa->value - pb->value;
    }
}

int main() {
    int n = 0, x;
    struct Number arr[MAXN];
    // 读入整数，计算位数并保存到结构体数组中
    while (scanf("%d", &x) != EOF) {
        arr[n].value = x;
        arr[n].digits = getDigits(x);
        n++;
    }
    // 对结构体数组进行排序
    qsort(arr, n, sizeof(struct Number), cmp);
    // 输出排序后的整数
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i].value);
        if (i != n - 1) {
            printf(" ");
        }
    }
    return 0;
}
