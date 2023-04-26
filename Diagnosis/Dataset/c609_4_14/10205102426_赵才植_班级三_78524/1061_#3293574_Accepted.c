#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 1000

int n;
long long int dp[MAX_N + 1];
bool b[MAX_N + 1];

void prime() {
    for (int i = 2; i <= MAX_N / 2; i++) {
        if (!b[i]) {
            for (int j = 2; i * j <= MAX_N; j++) {
                b[i * j] = true;
            }
        }
    }
}

int main() {
    prime();
    scanf("%d", &n);

    dp[0] = 1;
    for (int i = 2; i <= n; i++) {
        if (!b[i]) {
            for (int j = i; j <= n; j++) {
                dp[j] += dp[j - i];
            }
        }
    }

    printf("%lld\n", dp[n]);
    exit(0);
}
