#include<stdio.h>
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int n,k;
    scanf("%d %d",&k,&n);
    long long int dp[200];
    for(int i=0;i<200;i++) dp[i]=0;
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;i++)
    {
        for(int j=1;j<=k;j++) dp[i]+=dp[max(0,i-j)];
    }
    printf("%lld",dp[n]);
}