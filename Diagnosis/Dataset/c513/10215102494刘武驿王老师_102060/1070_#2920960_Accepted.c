#include<stdio.h>
int main()
{
    long long int dp[30];
    dp[0]=1;
    dp[1]=2;
    dp[2]=4;
    dp[3]=7;
    for(int i=4;i<21;i++)
    {
        dp[i]=2*dp[i-1]-(dp[i-1]-dp[i-4]-dp[i-3])/2;
    }
    int n;
    scanf("%d",&n);
    while(n!=-1)
    {
        printf("%lld\n",dp[n]);
        scanf("%d",&n);
    }
}
