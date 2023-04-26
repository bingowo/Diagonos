#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    long long *_a = (long long *)a;
    long long *_b = (long long *)b;
    return *_a - *_b;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    long long *arr[1000000];
    for(int i = 0; i < n ; i++)
    {
        long long t;
        scanf("%lld",&t);
        arr[i] = t;
    }
    qsort(arr, n, sizeof(arr[0]), cmp);
    long long *brr[1000000];
    for(int i = 0; i < n - m + 1 ; i++)
    {
        brr[i] = 0;
    }
    for(int i = 0; i < n - m + 1; i++)
    {
        for(int j = 1 ; j < m; j++)
        {
            brr[i] += arr[i] - arr[i + j];
        }
    }
    qsort(brr, n - m + 1, sizeof(brr[0]), cmp);
    printf("%lld\n",brr[n - m]);
    return 0;
}
