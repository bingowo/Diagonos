#include <stdio.h>

int f(int n) {
    if (n < 3)
        return n * 2;
    if (n == 3)
        return 7;
    int dp[n+1][2];
    dp[1][0] = dp[1][1] = 1;
    dp[2][0] = dp[2][1] = 2;
    dp[3][0] = 4;
    dp[3][1] = 3;
    for (int i = 4; i <= n; ++i) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][1] + dp[i-2][0];
    }
    return dp[n][0] + dp[n][1];
}

int main() {
    int n;
    while(scanf("%d", &n) && n != -1) {
        printf("%d\n", f(n));
    }
    return 0;
}