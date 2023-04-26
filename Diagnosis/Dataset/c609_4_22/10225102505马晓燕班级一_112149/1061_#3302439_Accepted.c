#include <stdio.h>
#include <stdlib.h>
#define N 1000

void findPrimes1(int* primes)
{
    int flag;
    for(int i=2;i<N;i++)
    {
        flag=1;
        for(int j=2;j*j<=i;j++)
            if(i%j==0)
                {flag=0; break;}
        if(flag)
            *primes++= i;
    }
    *primes=N+1;
}
//long long ans[N+1][200]={0};
long long search(int n,int start,int *primes)//记忆化搜索
{
    static long long ans[N+1][200]={0};
    if(!ans[n][start])
    {
        int i;
        if(!n)
            return ans[n][start]=1;
        for(i=start;primes[i]<=n;i++)
        {
            ans[n][start]+=search(n-primes[i],i,primes);
        }
    }
    return ans[n][start];
}
long long search3(int n,int start,int*primes)
{
    long long dp[N+1]={1};
    for(int i=start;primes[i]<=n;i++)
    {
        for(int x=primes[i];x<=n;x++)
            dp[x] += dp[x-primes[i]];
    }
    return dp[n];
}
int main()
{
    int n;
    scanf("%d",&n);
    int primes[200]={0};
    findPrimes1(primes);
    
    printf("%lld",search(n,0,primes));

    return 0;
}