#include <stdio.h>

// 对数组进行去重操作
int removeDuplicates(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (arr[i] == arr[j]) {
                arr[j] = -1; // 标记为-1表示需要去除
            }
        }
    }

    // 将标记为-1的元素移动到数组末尾
    int count = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] != -1) {
            arr[count++] = arr[i];
        }
    }

    return count;
}

// 根据排序方式对数组进行排序
void sortArray(int arr[], int n, char order) {
    int i, j;
    int temp;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if ((order == 'A' && arr[i] > arr[j]) || (order == 'D' && arr[i] < arr[j])) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    char order;
    scanf("%c", &order); // 输入排序方式
    int arr[1000];
    int n = 0;
    while (scanf("%d", &arr[n++]) != EOF) {} // 输入整数，直到遇到文件结束符为止

    n = removeDuplicates(arr, n-1); // 去重
    sortArray(arr, n, order); // 排序

    // 输出结果
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d", arr[n-1]); // 最后一个数后没有空格

    return 0;
}
