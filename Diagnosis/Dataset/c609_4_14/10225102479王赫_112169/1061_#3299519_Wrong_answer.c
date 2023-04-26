#include <stdio.h>
#define N 1005

int n;
long long dp[N];
int prime[N];

int ck_prime(int x)
{
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0) return 0;
    }
    return 1;
}

int sieve()
{
    int cnt=0;
    for(int i=2;i<N;i++)
    {
        if(ck_prime(i)) prime[cnt++]=i;
    }
    return cnt;
}
int main()
{
    scanf("%d",&n);
    int np=sieve();
    dp[0]=1;
    for(int i=0;i<np&&prime[i]<n;i++)
    {
        for(int j=prime[i];j<n;j++)
        {
            dp[j]+=dp[j-prime[i]];
        }
        printf("%lld\n",dp[n]);
        return 0;
    }
}
