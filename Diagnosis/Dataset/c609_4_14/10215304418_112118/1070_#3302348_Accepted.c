#include <stdio.h>
#include <stdlib.h>

long long dp[5][30];

int main()
{
    dp[0][1]=1;
    dp[1][1]=1;
    dp[4][1]=2;
    dp[0][2]=1;
    dp[1][2]=1;
    dp[2][2]=1;
    dp[3][2]=1;
    dp[4][2]=4;
    for (int i=3;i<=20;i++){
        dp[0][i]=dp[0][i-1]+dp[1][i-1];
        dp[1][i]=dp[2][i-1]+dp[3][i-1];
        dp[2][i]=dp[0][i-1];
        dp[3][i]=dp[2][i-1]+dp[3][i-1];
        dp[4][i]=dp[0][i]+dp[1][i]+dp[2][i]+dp[3][i];
    }
    int x;
    scanf("%d",&x);
    while (x!=-1){
        printf("%lld\n",dp[4][x]);
        scanf("%d",&x);
    }
    return 0;
}
