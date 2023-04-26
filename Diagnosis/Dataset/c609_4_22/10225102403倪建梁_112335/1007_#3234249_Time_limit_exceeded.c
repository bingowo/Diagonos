#include <stdio.h>
#include <stdlib.h>

// 计算一个整数的二进制补码表示中1的位数
int count_bits(long long num) {
    int count = 0;
    while (num != 0) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

// 自定义的比较函数，用于排序
int compare(const void *a, const void *b) {
    long long num1 = *(const long long *)a;
    long long num2 = *(const long long *)b;
    int bits1 = count_bits(num1);
    int bits2 = count_bits(num2);
    if (bits1 != bits2) {
        return bits2 - bits1;
    } else {
        return num1 - num2;
    }
}

// 打印数组
void print_array(long long arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%lld ", arr[i]);
    }
    printf("\n");
}

int main() {
    int t; // 问题数
    scanf("%d", &t);
    int i;
    for (i = 0; i < t; i++) {
        int n; // 数组中元素的个数
        scanf("%d", &n);
        long long arr[n]; // 数组元素
        int j;
        for (j = 0; j < n; j++) {
            scanf("%lld", &arr[j]);
        }
        qsort(arr, n, sizeof(long long), compare);
        printf("case #%d:\n", i);
        print_array(arr, n);
    }
    return 0;
}