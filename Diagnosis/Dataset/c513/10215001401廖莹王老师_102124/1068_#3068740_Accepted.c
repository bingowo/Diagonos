#include <stdio.h>
#include <stdlib.h>
long long p[31]={0};
void xiangcheng(long long p[32])
{
    int i;
    p[0]=1;
    for(i=1;i<32;i++)
    {
        p[i]=p[i-1]*2;
    }
}
int main()
{
    long long n,m;
    xiangcheng(p);
    while(1)
    {
        scanf("%lld %lld",&n,&m);
        if(n==-1 && m==-1)return 0;
        long long f[35];
        memset(f,0,sizeof(f));
        long long i,j,k;
        for(i=1;i<=n;i++)
        {
            if(i<m)f[i]=p[i];
            if(i==m)f[i]=p[i]-1;
            if(i>m){for(j=1;j<=m;j++)f[i]=f[i]+f[i-j];}
        }
        k=p[n]-f[n];
        printf("%lld\n",k);
    }
    return 0;
}
