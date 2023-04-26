#include <stdio.h>
long long dp[41][41];
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1; i<=40; ++i)
        dp[i][0] = dp[i][i] = 1;
    for(int i=2; i<=40; ++i)
        for(int j=1; j<i; ++j)
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
    for(int j=0; j<T; ++j) {
        int m, n;
        scanf("%d %d",&m, &n);
        printf("case #%d:\n%lld\n",j,dp[m][n]);
    }
    return 0;
}
