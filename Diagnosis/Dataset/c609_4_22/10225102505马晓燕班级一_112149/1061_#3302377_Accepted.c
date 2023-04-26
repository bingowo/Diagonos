#include <stdio.h>
#include <stdlib.h>
#define N 1000
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
int main()
{
    int n;
    scanf("%d",&n);
    int primes[200]={0},cnt=0;
    int flag;//存放素数

    for(int i=2;i<N;i++)
    {
        flag=1;
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0)
                {flag=0; break;}
        }
        if(flag)
            primes[cnt++]= i;
    }
    primes[cnt++]=N+1;
    printf("%lld",search(n,0,primes));

    return 0;
}
