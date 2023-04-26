#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cmp(const void *a, const void *b)
{
    long long m = *(long long*)a, n = *(long long*)b;
    int km = 0, kn = 0;
    long long m1 = m, n1 = n;
    while(m != 0)
    {
        m &= m -1;
        km++;
    }
    while(n != 0)
    {
        n &= n -1;
        kn++;
    }
    if(km < kn)
        return 1;
    if(km > kn)
        return -1;
    if(km == kn)
    {
        if(m1 > n1)
            return 1;
        else
            return -1;
        
    }
}

int main()
{
    int T,N,i,j;
    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        scanf("%d", &N);
        long long num[N];
        for(j=0; j<N; j++)
            scanf("%lld", &num[j]);

        qsort(num, N, sizeof(long long), cmp);
        printf("case #%d:\n", i);
        for(j=0; j<N; j++)
            printf("%lld ", num[j]);
        printf("\n");

    }

    return 0;
}
