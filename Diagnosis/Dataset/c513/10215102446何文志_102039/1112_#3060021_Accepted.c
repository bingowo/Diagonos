#include <stdlib.h>
#include <stdio.h>

int coef[4] = {1, 2, 3, 4};

int main(){
    int T = 0;
    scanf("%d", &T);
    for(int i = 0;i<T;++i){
        int n = 0;
        scanf("%d", &n);
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int j = 1;j<=4;j++){
            for(int k = j;k<=n;k++){
                dp[k] += dp[k-j];
            }
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
