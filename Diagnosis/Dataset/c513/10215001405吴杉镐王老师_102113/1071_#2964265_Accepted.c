#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 10007
int T,a,b,k,n,m;
int fac[10005];

int solve(int x,int y)
{
    int res=x,ans=1;
    while(y)
    {
        if(y%2)
            ans=ans*res%M;
        res=res*res%M;
        y>>=1;
    }
    return ans;
}

int main()
{
    fac[0]=1;
    for(int i=1;i<=10000;i++)
        fac[i]=fac[i-1]*i%M;
    scanf("%d",&T);
    for(int c=0;c<T;c++)
    {
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        a%=M;
        b%=M;
        printf("case #%d:\n%d\n",c,
               solve(a,n)*solve(b,m)%M*fac[k]%M*solve(fac[n],M-2)%M*solve(fac[k-n],M-2)%M);
    }
    return 0;
}