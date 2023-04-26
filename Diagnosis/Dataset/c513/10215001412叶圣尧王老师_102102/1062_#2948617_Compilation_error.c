#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void f(int n,char*dp)
{
    long long result=0;
    if(dp[n]!=0)return dp[n];
    if(n==1)return 1;
    else if(n==2)return 2;
    else if(n==3)return 4;
    else if(n==4)return 8;
    else result=f(n-1,dp)+f(n-2,dp)+f(n-3,dp)+f(n-4,dp);
    dp[n]=result;
}

int main()
{
    int T;int n;long long dp[51]={0};
    scanf("%d",&T);
    void f(50,dp);
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        scanf("%d",&n);
        printf("%lld\n",dp[n]);
    }
}
