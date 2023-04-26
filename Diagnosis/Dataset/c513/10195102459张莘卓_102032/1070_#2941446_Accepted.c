#include <stdio.h>
int main()
{
    int n, dp[21] = {0,2,4,7};
    for(int i=4; i<=20; ++i) {
        dp[i] = 2*dp[i-1] - dp[i-2] + dp[i-3];
    }
    while(scanf("%d",&n)) {
        if(n == -1) break;
        printf("%d\n",dp[n]);
    }
    return 0;
}