#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    long long dp[80];
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    for(int i=3;i<75;i++) dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    for(int i=0;i<n;i++)
    {
        int m;
        scanf("%d",&m);
        printf("case #%d:\n%lld\n",i,dp[m]);
    }

}