#include <stdio.h>
#include <stdlib.h>
// 计算一个整数的二进制补码表示中1的位数
int count_bits(long long num) {
    int count = 0;
    while (num) {
        num=num&(num-1);
        count++;
    }
    return count;
}

// 自定义的比较函数，用于排序
int compare(const void *a, const void *b) {
    long long num1 = *(const long long *)a;
    long long num2 = *(const long long *)b;
    int bits1 = count_bits(num1);
    int bits2 = count_bits(num2);
    if (bits1 > bits2) {return -1;}
    else if(bits1 < bits2) {return 1;}
    else if(bits1 = bits2) 
    {
        if (num1>num2) return 1;
        if (num1>=num2) return -1;
    }
}

int main() {
    int t; 
    scanf("%d", &t);
    int i;
    for (i = 0; i < t; i++) {
        int n; 
        scanf("%d", &n);
        long long arr[n]; 
        int j,k;
        for (j = 0; j < n; j++) {
            scanf("%lld", &arr[j]);}
        qsort(arr, n, sizeof(long long), compare);
        printf("case #%d:\n", i);
        for (k = 0; k < n; k++) {printf("%lld ", arr[k]);}
        printf("\n");
    }
    return 0;
}