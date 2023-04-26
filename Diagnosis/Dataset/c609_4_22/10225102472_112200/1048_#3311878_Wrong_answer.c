#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int T;
    scanf("%d", &T);
    for(int k = 0; k < T; k++)
    {
        long long dp[120] = {0};
        int n;
        scanf("%d", &n);
        dp[0] = 0;
        dp[1] = dp[2] = 1;
        for(int i = 3; i <= n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        printf("case #%d:\n", k);
        printf("%lld\n", dp[n]);
    }

    return 0;
}
