#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int atob(long long n, int r)
{
    //printf("%d %d\n",n,r);
    int i,p;
    int j;
    int k = 0;
    char s[10000];
    int m = 0;
    while(n>0)
    {
        p = n%r;
        if(p<10)
        {
            s[m] = '0'+p;
            m++;
        }
        else
        {
            s[m] = 'A'+p-10;
            m++;
        }
        n /= r;
    }
    for(j=m-1; j>=0; j--)
    {
        if(s[j] == '1')
            k++;
    }
    return k;
}

int cmp(const void *a, const void *b)
{
    long long m = *(long long*)a, n = *(long long*)b;
    int km = 0, kn = 0;
    long long m1 = m, n1 = n;
    if(m<0)
    {
        m = ~m + 1;
        km = atob(m,2) + 1;
    }
    else
        km = atob(m,2);
    if(n<0)
    {
        n = ~n + 1;
        kn = atob(n,2) + 1;
    }
    else
        kn = atob(n,2);
    if(km != kn)
        return kn - km;
    else
        return m1 - n1;

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
        for(j=0; j<N; j++)
            printf("case #%d:\n%lld\n", i, num[j]);

    }

    return 0;
}
