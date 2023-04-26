#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n,i,sum=0;
    int nums[100000];
    scanf("%d", &n); // 输入n
    for (i = 0; i < n; i++) {
        scanf("%d", &nums[i]); // 输入n个整数
    }
    qsort(nums, n, sizeof(int), cmp); // 对nums进行排序，使得相邻两个数的差的绝对值最小
    for (i = 1; i < n; i += 2) {
        sum += abs(nums[i]-nums[i-1]); // 计算相邻两个数的差的绝对值，并求和
    }
    printf("%d\n", sum); // 输出和的最小值
    return 0;
}




