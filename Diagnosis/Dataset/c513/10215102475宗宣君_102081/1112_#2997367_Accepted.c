#include <stdio.h>
int dp[1111];

int main() {
    int n, t,i,j;
    dp[0] = 1;
    int type[4] = {4, 3, 2, 1};
    for (i = 0; i < 4; i++) {
        for (j = type[i]; j <= 1000; j++) {
            dp[j] += dp[j - type[i]];
        }
    }
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
    return 0;
}
