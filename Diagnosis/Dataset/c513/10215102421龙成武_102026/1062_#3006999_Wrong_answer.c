#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
long long int dp[51]={0,1,2,4,8};
long long int calit(long long int n)
{
    if(dp[n]==0)
        dp[n]=calit(n-1)+calit(n-2)+calit(n-3)+calit(n-4);
    return dp[n];
}
int main()
{
    int T,i;
    long long int n,ans;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%lld",&n);
        ans=calit(n);
        printf("case #%d:\n%lld",i,ans);
    }
    return 0;
}
