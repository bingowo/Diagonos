#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b);

int main()
{
    int nums[1000000];
    int n = 0;

    // 读取输入
    while (scanf("%d", &nums[n]) != EOF) {
        n++;
    }

    // 使用 qsort() 函数进行排序
    qsort(nums, n, sizeof(int), compare);

    // 输出排序结果
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}

// 比较函数，用于 qsort() 函数的排序
int compare(const void *a, const void *b) {
    int x = *(const int*)a;
    int y = *(const int*)b;

    // 比较两个数的位数
    int digits_x = snprintf(NULL, 0, "%d", x);
    int digits_y = snprintf(NULL, 0, "%d", y);
    if(x<0)digits_x--;
    if(y<0)digits_y--;
    if (digits_x > digits_y) {
        return -1;
    }
    else if (digits_x < digits_y) {
        return 1;
    } else {
        // 如果位数相同，则比较本身的大小
        if (x > y) {
            return 1;
        } else if (x < y) {
            return -1;
        } else {
            return 0;
        }
    }
}
