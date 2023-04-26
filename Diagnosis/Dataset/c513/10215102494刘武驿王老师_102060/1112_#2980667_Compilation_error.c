#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    long long int dp[10000];
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    for(int i=4;i<1001;i++)
    {
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4];
    }
    for(int i=0;i<n;i++)
    {
        int p;
        scanf("%d",&p);
        printf("%lld\n",dp[]);
    }
}