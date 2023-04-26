#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define N 10007


int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        long long int a,b,k,n,m,ans;
        scanf("%lld%lld%lld%lld%lld",&a,&b,&k,&n,&m);
        long long  int dp[1100][1100];
        dp[0][0]=1;
        for (int i=0;i<=n;i++) 
        for (int j=0;j<=m;j++)
        if (i+j)
        { if (i==0) dp[i][j] = b*dp[i][j-1]%N;
          else if (j==0) dp[i][j] = a*dp[i-1][j]%N;
          else dp[i][j] = (a*dp[i-1][j]+b*dp[i][j-1])%N;}
        printf("case #%d:\n",i);
        printf("%lld\n",dp[n][m]);
        
    }
    return 0;
}