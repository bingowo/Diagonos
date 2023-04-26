#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), cmp);
    int min = 0;
    for (int i = 0; i < n / 2; i++)
    {
        min += (arr[2 * i + 1] - arr[2 * i]);
    }
    free(arr);
    printf("%d", min);
    return 0;
}