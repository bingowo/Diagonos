#include <stdlib.h>
#include <stdio.h>

int comp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int Unique(int arr[], int len)
{
    if (!arr || len <= 0) return 0;

    qsort(arr, len, sizeof(int), comp);

    int k = 0;
    for (int i = 1; i < len; i++)
    {
        if (arr[k] != arr[i])
        {
            arr[k + 1] = arr[i]; // arr[k + 1] 始终指向“当前已得到的无重复数组”的最后一个元素。
            k++; // k++后，k 对应的既是“当前已得到的无重复数组”的最后一个元素的下标。
        }

    }

    return (k + 1); // 去重后，数组的长度
}

int main(int argc, const char * argv[]) {

    int arr[] = {1,2,3,5,9,6,5,5,3,7};
    int len = sizeof(arr)/sizeof(int);

    int newLen = Unique(arr, len);

    for (int i = 0; i < newLen; i++)
        printf("%d  ", arr[i]);
    printf("\n");

    return 0;
}