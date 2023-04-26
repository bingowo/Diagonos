#include <stdio.h>
#include <math.h>
#define MAX 2e18
struct power//a^b
{
    long long a;
    int b;
}ans[100];

long long intpow(long long n,int k)//快速幂计算n^k
{
    if(k==1) return n;
    long long int p=1;
    while(k>0)
    {
        if(p>=MAX/n) return MAX;//数据溢出
        
        if(k&1) p=p*n;
        n=n*n;
        k=k>>1;
    }
    return p;
}

long long kroot(long long n,int k)//二分法计算n的k次根
{
    long long m=n; int t=k;
    while(t>1) {m=sqrt(m);t=t>>1;}//缩小搜索范围，[2,n的(2^i)次根],(2^i)<=k

    long long int L=2,R=m,mid;
    while(L<=R)
    {
        mid=(L+R)/2;
        long long p=intpow(mid,k);
        if(p==n) return mid;
        else if(p>n) R=mid-1;
        else L=mid+1;
    }
    return -1;
}

void computepow(long long n,int* cnt)//枚举n的k次根(k=2,3,4,...)
{
    if(n==1) {*cnt=0; return;}
    for(int i=2;i<=64 && intpow(2,i)<=MAX;i++)
    {
        long long p=kroot(n,i);
        if(p!=-1)
        {
            ans[*cnt].a=p;ans[*cnt].b=i;(*cnt)++;
        }
    }
}
int main()
{
    int T;scanf("%d",&T);
    for(int i=0; i<T; i++)
    {
        long long int n;
        scanf("%lld",&n);
        int cnt=0;
        computepow(n,&cnt);
        if(cnt==0)
        {
            printf("%lld is powerless.\n",n);
        }
        else
        {
            printf("%lld",n);
            for(int j=0;j<cnt;j++)
            {
                printf("=%lld^%d",ans[j].a,ans[j].b);
            }
            printf("\n");
        }
    }
    return 0;
}

