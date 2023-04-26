#include <stdio.h>
#include <stdlib.h>
#define N 1000

//素数表,埃拉托斯特尼筛法
void findPrimes2(int *primes)
{
    int i,j,b[N+1];
    for(i=2;i<=N;i++)b[i]=1;
    for(i=2;i*i<N;i++)
        if(b[i])for(j=2;i*j<=N;j++)b[i*j]=0;
    for(i=2;i<=N;i++)
        if(b[i])*primes++=i;
    *primes=N+1;//设置边界
}

//记忆化搜索
long long search2(int n,int start,int *primes)
{
    static long long ans[N+1][200]={0};
    if(!ans[n][start])
    {
        int i;
        if(!n)return ans[n][start]=1;
        for(i=start;primes[i]<=n;i++)
        {
            ans[n][start]+=search2(n-primes[i],i,primes);
        }
    }
    return ans[n][start];
}

int main()
{
    int primes[168];
    findPrimes2(primes);
    int n;
    scanf("%d",&n);
    printf("%lld",search2(n,0,primes));
    return 0;
}
