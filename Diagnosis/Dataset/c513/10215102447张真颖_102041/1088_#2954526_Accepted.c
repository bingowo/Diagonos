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
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int m=0,n=0;
        long long re=1;
        scanf("%d%d",&m,&n);
        if(n)
            re=c(m,n,re);
        printf("case #%d:\n%lld\n",i,re);
    }
    return 0;
}
