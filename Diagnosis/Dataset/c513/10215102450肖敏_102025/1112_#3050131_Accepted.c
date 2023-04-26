#include <stdio.h>
#include <string.h>

#define N 1001
int dp[N];

int main() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= 4; i++) {
        for (int j = i; j <= 1000; j++) {
            dp[j] += dp[j - i];
        }
    }
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
    return 0;
}