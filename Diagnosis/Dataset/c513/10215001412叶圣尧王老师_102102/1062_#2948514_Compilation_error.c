#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

long long f(int n)
{
    long long result=0;
    if(dp[n]!=0)return dp[n];
    if(n==1)return 1;
    else if(n==2)return 2;
    else if(n==3)return 4;
    else if(n==4)return 8;
    result=f(n-1)+f(n-2)+f(n-3)+f(n-4);
    dp[n]=result;
    return result;
}

int main()
{
    int T;int n;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        scanf("%d",&n);long long dp[n+1];
        long long f(int n);
        long long sum;
        sum=f(n);
        printf("%lld\n",sum);
    }
}
