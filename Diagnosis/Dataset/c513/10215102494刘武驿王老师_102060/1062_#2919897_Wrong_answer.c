#include<stdio.h>
int main()
{
    long long int dp[60];
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    dp[4]=8;
    for(int i=5;i<55;i++)
    {
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4];
    }
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int m;
        scanf("%d",&m);
        printf("case #%d:\n%lld",i,dp[m]);
    }
}
