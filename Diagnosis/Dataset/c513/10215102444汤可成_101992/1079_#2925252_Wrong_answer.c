#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    long long int* pa = (long long int*)a;
    long long int* pb = (long long int*)b;
    if(*pa > *pb) return 1;
    else return -1;
}

int main()

{
    int T = 0;
    int i = 0;
    scanf("%d", &T);
    for(i = 0; i<T; i++)
    {
        printf("case #%d:\n", i);
        int n = 0;
        int m = 0;
        scanf("%d %d", &n, &m);
        int j = 0;
        int a[1001] = {0};
        long long int b[500501] = {0};
        int cnt = 0;
        for(j = 1; j<=n; j++)
        {
            scanf("%d", a+j);
            a[j] += a[j-1];
        }
        int len = 0;
        for(len = 1; len<=n; len++)
            for(j = 0; j<=n-len+1; j++)
            {
                b[++cnt] = a[i+len-1]-a[i-1];
            }
        qsort(b, n*(n+1)/2, sizeof(b[0]), cmp);
        for(j = 1; j<=cnt; j++) b[j] += b[j-1];
        for(j = 0; j<m; j++)
        {
            int L = 0, U = 0;
            scanf("%d %d",&L,&U);
            printf("%lld\n", b[U]-b[L-1]);
        }
    }
    return 0;
}
