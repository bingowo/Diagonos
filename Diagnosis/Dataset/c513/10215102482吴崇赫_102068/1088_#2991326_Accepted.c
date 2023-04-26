#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 45

int main()
{
    int T,x=0;
    scanf("%d\n",&T);
    long long dp[N][N];
    dp[0][0]=0;dp[1][1]=dp[1][0]=1;
    for(int i=2;i<=40;++i){
        for(int j=1;j<i;++j)dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        dp[i][i]=dp[i][0]=1;
    }
    while(x<T){
        int m,n;
        scanf("%d%d",&m,&n);
        printf("case #%d:\n",x++);
        printf("%lld\n",dp[m][n]);
    }
    return 0;
}