#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long dp[80];
long long getit(int n)
{
    long long val;
    if(n==0)
        val=0;
    else if(n==1||n==2)
        val=1;
    else
    {
        if(dp[n]==-1)
        {
            val=getit(n-1)+getit(n-2)+getit(n-3);
        }
        else
        {
            val=dp[n];
        }
    }
    if(dp[n]==-1)
        dp[n]=val;
    return val;
}
int main()
{
    int n,x,T;
    scanf("%d", &T);
    for(x=0;x<T;x++)
    {
        scanf("%d",&n);
        memset(dp,-1,sizeof(dp));
        printf("case #%d:\n",x);
        printf("%lld\n",getit(n));
    }

    return 0;
}

