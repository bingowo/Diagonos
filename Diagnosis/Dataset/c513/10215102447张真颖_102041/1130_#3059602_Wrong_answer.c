#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 2e18

typedef struct
{
    long long a;
    int b;
}TYPE;

long long intpow(long long n,int k)
{
    if(k==1) return n;

    long long p=1;
    while(k>0)
    {
        if(p>=MAX/n) return MAX;

        if(k&1) p=p*n;
        n=n*n;
        k=k>>1;
    }
    return p;
}

long long kroot(long long n,int k)
{
    long long int m=n;
    int t=k;
    while(t>1) {m=sqrt(m);t=t>>1;}

    long long L=2,R=m,mid;
    while(L<=R)
    {
        mid=(L+R)/2;
        long long p=intpow(mid,k);
        if(p>n) R=mid-1;
        else if(p<n) L=mid+1;
        else return mid;
    }
    return -1;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        long long int n=0;
        scanf("%lld",&n);
        int cnt=0;
        TYPE ans[64]={0,0};

        if(n>1)
        {
            for(int i=2;i<=64&&intpow(2,i)<=MAX;i++)
            {
                long long p=kroot(n,i);
                if(p!=-1)
                {
                    ans[cnt].a=p;
                    ans[cnt].b=i;
                    cnt++;
                }
            }
        }

        if(cnt==0) printf("%lld is powerless.\n",n);
        else
        {
            printf("%d=",n);
            for(int i=0;i<cnt;i++)
                printf("%lld^%d%c",ans[i].a,ans[i].b,i==cnt-1?'\n':'=');

        }

    }
    return 0;
}  