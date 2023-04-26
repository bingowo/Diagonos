#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ll long long
#define ull unsigned long long
#define MAXN 10010
int dp[MAXN][3][3];

int main()
{
    int n;
    memset(dp, 0, sizeof(dp));
    dp[2][0][1] = 1;
    dp[2][0][0] = 1;
    dp[2][1][0] = 1;
    dp[2][1][1] = 1;
    for (int i = 3; i <= MAXN; ++i)
    {
        dp[i][0][1] = dp[i - 1][0][0];
        dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][1][0]);
        dp[i][1][0] = (dp[i - 1][0][1] + dp[i - 1][1][1]);
        dp[i][1][1] = (dp[i - 1][1][1] + dp[i - 1][0][1]);
    }
    while (scanf("%d", &n) && (n != -1))
    {
        if (n == 1)
        {
            printf("2\n");
            continue;
        }
        printf("%d\n", (dp[n][0][0] + dp[n][0][1] + dp[n][1][0] + dp[n][1][1]));
    }
    return 0;
}