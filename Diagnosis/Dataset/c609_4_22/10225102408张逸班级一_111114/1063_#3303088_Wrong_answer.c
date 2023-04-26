#include <stdio.h>

#define MAXN 100

long long dp[MAXN+1];

long long count_ways(int n) {
    int i, j;
    dp[0] = dp[1] = 1;
    for (i = 2; i <= n; i++) {
        dp[i] = 0;
        for (j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    return dp[n];
}

int main() {
    int n = 50;
    long long ways = count_ways(n);
    printf("n = %d, ways = %lld\n", n, ways);
    return 0;
}