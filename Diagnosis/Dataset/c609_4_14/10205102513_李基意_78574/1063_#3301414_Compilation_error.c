#include<stdio.h>
#include<stdlib.h>

int main() {
    long long int dp[51];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    for (int i = 5; i <= 50; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
    }
    int T;
    scanf("%d",&T);
    for (int i = 0; l < T; i++) {
        int n;
        scanf("%d",&n);
        printf("case #i:\n%lld\n",dp[k]);
    }
    return 0;
}