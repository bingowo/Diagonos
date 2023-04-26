#include <stdio.h>
#include <string.h>

int main() {
    int n, k;
    scanf("%d%d", &k, &n);
    if (n == 2) {
        printf("1");
        return 0;
    }
    if (n <= k) {
        printf("0");
        return 0;
    }

    long long dp[n];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= k; ++i) {
        dp[i] = dp[i-1] * 2;
    }

    for (int i = k + 1; i < n; ++i) {
        dp[i] = dp[i-1] * 2 - dp[i-k-1];
    }


    // for (int i = 0; i < n; ++i) {
    //     printf("%d: %lld\n",i, dp[i]);
    // }

    printf("%lld", dp[n-1]);
    return 0;
}