#include <stdio.h>
#include <stdlib.h>
long long a[33]={0};
long long f(int n,int m)
{
    if(n<m) return 0;
    if(n==m) return 1;
    if(n>m&&a[n]==0) a[n]=2*f(n-1,m)-f(n-1-m,m)+(1<<(n-m-1));
    return a[n];
}
int main()
{
    int t=1;
    while(t)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if(n==-1&&m==-1) break;
        long long sum;
        sum=f(n,m);
        printf("%lld\n",sum);
        for(int i=0;i<33;i++) a[i]=0;
    }
    return 0;
}
