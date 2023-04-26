#include <stdio.h>
#include <stdlib.h>

long long cmp(const void *a,const void *b)
{
    long long _a = *((long long *)a);
    long long _b = *((long long *)b);
    return _a - _b;
}

int main()
{
    long long n,m;
    scanf("%lld% lld",&n,&m);
    long long arr[1000000];
    for(int i = 0; i < n ; i++)
    {
        long long t;
        scanf("%lld",&t);
        arr[i] = t;
    }
    qsort(arr, n, sizeof(arr[0]), cmp);

    long long brr[1000000];

    for(int i = 0; i < n - 1 ; i++)
    {
        brr[i] = arr[i] - arr[i + 1];
    }
    long long S = 0;

    for(int i = 0; i < m - 1;i++)
    {
        S += brr[i] * (m - i - 1);
    }
    long long min = S;

    for(int i = 0; i < n - m; i++)
    {
        S -= brr[i] * (m - 1);
        S += (arr[i + 1] - arr[i + m]);
        if(S < min)
            min = S;
    }
    printf("%lld\n",min);
    return 0;
}
