#include <stdio.h>

void bubble_sort(int arr[], int n, char order);

int main()
{
    char order;
    scanf("%c", &order); // 读入排序方式（A或D）

    int nums[100] = { 0 };
    int pos = 0;
    int temp, flag;

    // 循环读入数据，去重
    while (scanf("%d", &temp) != EOF) {
        int i;
        for (i = 0; i < pos; ++i) {  // 判断数据是否重复
            if (nums[i] == temp) {
                break;
            }
        }
        if (i == pos) {   // 数据未重复
            nums[pos++] = temp;
        }
    }

    // 排序
    bubble_sort(nums, pos, order);

    // 输出结果
    for (int i = 0; i < pos; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}

// 冒泡排序算法
void bubble_sort(int arr[], int n, char order)
{
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((order == 'A' && arr[j] > arr[j + 1]) || (order == 'D' && arr[j] < arr[j + 1])) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}