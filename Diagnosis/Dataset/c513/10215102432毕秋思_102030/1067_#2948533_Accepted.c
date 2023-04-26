#include<stdio.h>

long long sum(long long x)
{
    long long a[75];
    a[0]=0;
    a[1]=1;
    a[2]=1;
    for(int i=3;i<75;i++)
    {
        a[i]=a[i-1]+a[i-2]+a[i-3];
    }
    return a[x];
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",t);
        printf("%lld\n",sum(n));
    }
    return 0;
}
