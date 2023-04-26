#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1000
void findprime(int prime[])
{
    int flag,j=0;
    for(int i=2;i<N;i++)
    {
        flag=1;
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            prime[j]=i;
            j++;
        }
    }
}
long long search(int n,int start,int prime[])
{
    long long dp[N+1]={1};
    for(int i=start;prime[i]<=n;i++)
    {
        for(int x=prime[i];x<=n;x++)
        {
            dp[x]=dp[x]+dp[x-prime[i]];
        }
    }
    return dp[n];
}
int main()
{
    long long ans;
    int n,prime[500];
    findprime(prime);
    scanf("%d",&n);
    ans=search(n,0,prime);
    printf("%lld",ans);
    return 0;
}
