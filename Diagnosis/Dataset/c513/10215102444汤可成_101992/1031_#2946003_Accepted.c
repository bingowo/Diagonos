#include <stdio.h>
#include <stdlib.h>

int cmp_1(const void*pa, const void*pb)
{
    return *(int*)pa - *(int*)pb;
}

int cmp_2(const void*pa, const void*pb)
{
    return *(int*)pb- *(int*)pa;
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    int i = 0;
    for(i = 0; i<T; i++)
    {
        int n = 0;
        scanf("%d", &n);
        int arr1[1001] = {0};
        int arr2[1001] = {0};
        for(int j = 0; j<n; j++)
        {
            scanf("%d", &arr1[j]);
        }
        for(int j = 0; j<n; j++)
        {
            scanf("%d", &arr2[j]);
        }
        qsort(arr1, n, sizeof(int), cmp_1);
        qsort(arr2, n, sizeof(int), cmp_2);
        int num = 0;
        for(int j = 0; j<n; j++)
        {
            num += arr1[j]*arr2[j];
        }
        printf("case #%d:\n", i);
        printf("%d\n", num);
    }
    return 0;
}
