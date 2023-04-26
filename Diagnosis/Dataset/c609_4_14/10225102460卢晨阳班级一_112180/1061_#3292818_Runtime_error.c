
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#define MAX_N 200

int main() {
    int n;
    int dp[MAX_N + 1] = {0};
    int primes[MAX_N + 1] = {0};
    int cnt = 0;

    scanf("%d", &n);

    for (int i = 2; i <= n; ++i) {
        if (!primes[i]) {
            primes[cnt++] = i;
            dp[i] = 1;
        }
        for (int j = 0; primes[j] && primes[j] <= n / i; ++j) {
            primes[i * primes[j]] = 1;
            if (i % primes[j] == 0) {
                break;
            }
            dp[i * primes[j]] += dp[i];
        }
    }

    printf("%d\n", dp[n]);

    return 0;
}