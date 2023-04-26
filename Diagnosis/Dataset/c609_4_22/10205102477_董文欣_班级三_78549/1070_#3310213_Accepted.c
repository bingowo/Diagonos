#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int dp[21];
    dp[0] = 0;
    dp[1] = 2;
    dp[2] = 4;
    dp[3] = 7;
    for (int i = 4; i <= 20; i++)
    {
        dp[i] = dp[i-1] + dp[i-1] - dp[i-2] + dp[i-3];
    }
    while (scanf("%d",&n) != EOF && n != -1)
    {
        printf("%d\n", dp[n]);
    }
    return 0;
}
