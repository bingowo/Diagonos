#include <stdio.h>
#include <stdlib.h>

int cmp(const void*pa, const void* pb)
{
    long long *a = (long long*)pa;
    long long* b = (long long*)pb;
    if(*a > *b) return -1;
    else return 1;
}

int main()
{
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);
    int i = 0;
    long long* arr = (long long*)malloc(sizeof(long long)*n);
    for(i = 0; i<n; i++)
    {
        scanf("%lld",&arr[i]);
    }
    qsort(arr, n, sizeof(long long), cmp);
    long long max = 0;
    for(i = 0; i<m; i++)
    {
        max += arr[0] - arr[i];
    }
    long long ret = max;
    for(int j = m; j<n; j++)
    {
        max = max - (m-1)*(arr[j-m] - arr[j-m+1]) + arr[j-m+1]-arr[j];
        if(max < ret) ret = max;
    }
    printf("%lld", ret);
    free(arr);
    return 0;
}
