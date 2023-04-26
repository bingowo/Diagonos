#include <stdio.h>
#include <stdlib.h>

int main()
{

    int T;
    scanf ("%d", &T);
    long long dp[51] = {0};
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    for (int i = 0; i < T; i++) {
        int n;
        scanf ("%d", &n);
        for (int j = 5; j <= n; j++) {
            dp[j] = dp[j-1] + dp[j-2] + dp[j-3] + dp[j-4];
        }
        printf("case #%d:\n%lld\n", i, dp[n]);
    }
    return 0;
}
