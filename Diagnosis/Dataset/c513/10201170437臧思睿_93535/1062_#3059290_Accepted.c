#include <stdio.h>
typedef long long int ll;

int main()
{
    int i,t=0,T,x;
    ll dp[51];
    dp[1]=1;dp[2]=2;dp[3]=4;dp[4]=8;
    for(i=5;i<=50;i++)
    {
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4];
    }
    scanf("%d",&T);
    while(t++<T)
    {
        printf("case #%d:\n",t-1);
        scanf("%d",&x);
        printf("%lld\n",dp[x]);
    }
    return 0;
}
