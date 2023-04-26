#include<stdio.h>
int main()
{
    int n,w[200],sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
        sum+=w[i];
    }
    int dp[20][20000];
    for(int i=0;i<n;i++) for(int j=0;j<20000;j++) dp[i][j]=0;
    dp[1][10000+w[0]]=1;
    dp[1][10000-w[0]]=1;
    for(int i=0;i<20;i++) dp[i][10000]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=2*sum;j++)
        {
            if(dp[i-1][10000-sum+j-w[i-1]]==1||dp[i-1][10000-sum+j+w[i-1]]==1)
            {
                dp[i][10000-sum+j]=1;
            }
        }
    }
    int res[10000];
    for(int i=0;i<=sum;i++) res[i]=0;
    for(int i=1;i<=n;i++) for(int j=0;j<=sum;j++) if(dp[i][10000+j]==1) res[j]=1;
    for(int i=1;i<=sum;i++) printf("%d",res[i]);
}
