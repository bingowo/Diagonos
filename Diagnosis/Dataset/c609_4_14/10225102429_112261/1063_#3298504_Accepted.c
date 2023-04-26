#include <stdio.h>
#define N 51
long long dp[N];
int main(){
    dp[1] = 1,dp[2] = 2,dp[3] = 4,dp[4] = 8;
    for(int i = 5; i<N; i++){
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4];
    }
    int t; scanf("%d",&t);
    for(int i = 0; i<t; i++){
        printf("case #%d:\n",i);
        int n; scanf("%d",&n);
        printf("%lld\n",dp[n]);
    }
    return 0;
}