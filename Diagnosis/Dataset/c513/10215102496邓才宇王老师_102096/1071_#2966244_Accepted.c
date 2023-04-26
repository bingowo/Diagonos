#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        long long int dp[1001][1001];
        dp[0][0]=1;
        int a,b,k,n,m;
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        for(int j=0;j<=n;j++)
        {
            for(int k=0;k<=m;k++)
            {
                if(j+k)
                {
                    if(j==0) dp[j][k]=b*dp[j][k-1]%10007;
                    else if(k==0) dp[j][k]=a*dp[j-1][k]%10007;
                    else dp[j][k]=(a*dp[j-1][k]%10007+b*dp[j][k-1])%10007;
                }
            }
        }
        printf("case #%d:\n%lld\n",i,dp[n][m]);
    }
}
