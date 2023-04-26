#include <stdio.h>
#include <math.h>

#define MAX 2e18

struct power
{
    long long a;
    int b;
}ans[100];

long long intpow(long long n,int k)
{
    if(k==1)
        return n;
    long long p=1;
    while(k>0)
    {
        if(p>=MAX/n)//避免溢出
            return MAX;
        if(k&1)
            p*=n;
        n*=n;
        k>>=1;
    }
    return p;
}
//二分法计算n的k次方根
long long kroot(long long n,int k)
{
    long long m=n;
    int t=k;
    while(t>1)
    {
        m= sqrt(m);
        t>>=1;
    }
    long long L=2,R=m,mid;
    while(L<=R)
    {
        mid=(L+R)/2;
        long long p= intpow(mid,k);
        if(p==n)
        {
            return mid;
        }
        else if(p>n)
            R=mid-1;
        else
            L=mid+1;
    }
    return -1;
}

int computepow(long long n,int cnt)
{
    if(n==1)
    {
        cnt=0;
        return;
    }
    for(int i=2;i<=64;i++)
    {
        long long p= kroot(n,i);
        if(p!=-1)
        {
            ans[cnt].a=p;
            ans[cnt].b=i;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        long long n;
        scanf("%lld", &n);
        int cnt=0;
        int cnt2=computepow(n,cnt);
        if(cnt2==0)
        {
            printf("%lld is powerless.\n",n);
        }
        else
        {
            printf("%lld",n);
            for(int j=0;j<cnt2;j++)
            {
                printf("=%lld^%d",ans[j].a,ans[j].b);
            }
            printf("\n");
        }
    }
    return 0;
}
