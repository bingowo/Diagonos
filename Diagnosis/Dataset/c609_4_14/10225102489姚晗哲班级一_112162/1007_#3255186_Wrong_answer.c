#include <stdio.h>
#include <stdlib.h>

// 计算一个数的二进制中1的个数
int count_bits(long long num) {
    int count = 0;
    while (num != 0) {
        count++;
        num &= num - 1;
    }
    return count;
}

// 快速排序，按照1的个数从大到小排序，若1的个数相同，数字本身从小到大排序
void quick_sort(long long arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = count_bits(arr[left]);
    long long pivot_num = arr[left];
    int i = left, j = right;
    while (i < j) {
        while (i < j && (count_bits(arr[j]) < pivot || (count_bits(arr[j]) == pivot && arr[j] >= pivot_num))) {
            j--;
        }
        if (i < j) {
            arr[i] = arr[j];
            i++;
        }
        while (i < j && (count_bits(arr[i]) > pivot || (count_bits(arr[i]) == pivot && arr[i] < pivot_num))) {
            i++;
        }
        if (i < j) {
            arr[j] = arr[i];
            j--;
        }
    }
    arr[i] = pivot_num;
    quick_sort(arr, left, i - 1);
    quick_sort(arr, i + 1, right);
}

int main() {
    int n;
    scanf("%d", &n);
    long long arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%lld ", arr[i]);
    }
    printf("\n");
    return 0;
}
