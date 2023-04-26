#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int cmp(const void *a,const void *b)
{
    long long *a1=(long long*)a,*b1=(long long*)b;
    long long p=*a1<0?-*a1:*a1,q=*b1<0?-*b1:*b1;
    long long n=0,m=0;
    while (p>0)
    {
        n=p%10;
        p/=10;
    }
    while (q>0)
    {
        m=q%10;
        q/=10;
    }
    if (n!=m) return m-n;
    else
    {
        if (*a1>*b1) return 1;
        else return -1;
    }
}
int main()
{
    int T;
    scanf ("%d",&T);
    for (int i=0;i<T;i++)
    {
        long long N,s[10001]={0};
        scanf("%lld",&N);
        for (int j=0;j<N;j++)
        {
            scanf("%lld",&s[j]);
        }
        qsort(s,N,sizeof(s[0]),cmp);
        printf ("case #%d:\n",i);
        for (int j=0;j<N;j++)
        {
            printf("%lld%c",s[j],j==N-1?'\n':' ');
        }
    }
    return 0;
}
