//dp[n] = dp[n-1]+dp[n-2]+dp[n-3]+dp[n-4]
#include <stdio.h>
#include <string.h>
long long dp[55];
int main(){
    int T, n, ret;
    scanf("%d", &T);
    for(int t=0; t<T; t++){
        printf("case #%d:\n", t);
        scanf("%d", &n);
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=4&&i-j>=0; j++){
                dp[i] += dp[i-j];
            }
        }
        printf("%lld\n", dp[n]);
    }
}