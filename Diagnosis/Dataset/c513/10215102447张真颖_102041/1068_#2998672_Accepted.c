#include <stdio.h>
#include <stdlib.h>

long long f(int n,int m)
{
    if(n<m) return 0;
    else if(n==m) return 1;
    else return (long long)(2*f(n-1,m)-f(n-m-1,m)+(1<<(n-1-m)));
}

int main()
{
    int n=0,m=0;
    while(scanf("%d%d",&n,&m)!=EOF&&n!=-1&&m!=-1)
        printf("%lld\n",f(n,m));
    return 0;
}