#include <stdio.h>


long long int dp[41][41];
int main() {
    int num;
    scanf("%d",&num);
    for (int k = 0; k < num; ++k) {
        int m, n;
        scanf("%d%d",&m,&n);
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }
        printf("case #%d:\n%lld\n",k,dp[m][n]);
    }
    return 0;
}