#include <stdio.h>
#include <stdlib.h>

long long c(int m,int n,long long re)
{
    if(n==1)
    {
        re=m;
    }
    else
        re=c(m,n-1,re)*(m-n+1)/n;
    return re;
}

int main()
{
    int n=0,m=0;
    while(scanf("%d%d",&n,&m)!=EOF&&n!=-1&&m!=-1)
    {
        long long re0=n-m+1,re=0;
        for(int i=1;i<=n-m;i++)
            re+=c(n-m,i,re)*(n-m-i+1);
        printf("%lld\n",re+re0);
    }
    return 0;
}