#include <stdio.h>
#include <math.h>
#include <string.h>
#define ll long long
#define mod 10007

int A,B,M,N,K;
int dp[1010][1010];

int f(int n,int m,int a,int b)
{
    if (dp[n][m] != 0) return dp[n][m];
    if (n == 0 && m == 0) return dp[n][m] = 1;
    if (m == 0) dp[n][m] = (a%mod * f(n-1,m,a,b))%mod;
    else if (n == 0) dp[n][m] = (b%mod*f(n,m-1,a,b))%mod;
    else dp[n][m] = (a%mod*f(n-1,m,a,b) + b%mod*f(n,m-1,a,b))%mod;
    return dp[n][m];
}

int main()
{
    int n;scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        printf("case #%d:\n",i);
        scanf("%d %d %d %d %d",&A,&B,&K,&N,&M);
        printf("%d\n",f(N,M,A,B));
        memset(dp,0,sizeof(dp));
    }
    return 0;
}