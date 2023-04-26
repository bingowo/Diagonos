#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ll long long
#define ull unsigned long long
#define MAXN 10010
int dp[MAXN][2][2], n, ans[MAXN];

void init()
{
    memset(dp, 0, sizeof(dp));
    memset(ans, 0, sizeof(ans));
    ans[0] = 0;
    ans[1] = 2;
    ans[2] = 4;
    dp[2][0][0] = dp[2][0][1] = dp[2][1][0] = dp[2][1][1] = 1;
    dp[1][1][0] = dp[1][0][0] = 1;
    for (int i = 3; i < MAXN; i++)
    {
        dp[i][0][0] = (dp[i][0][0] + (dp[i - 1][0][1] + dp[i - 1][0][0]));
        dp[i][0][1] = (dp[i][0][1] + (dp[i - 1][1][0] + dp[i - 1][1][1]));
        dp[i][1][0] = (dp[i][1][0] + (dp[i - 1][0][0]));
        dp[i][1][1] = (dp[i][1][1] + (dp[i - 1][1][0] + dp[i - 1][1][1]));
        ans[i] = (dp[i][0][0] + dp[i][0][1] + dp[i][1][0] + dp[i][1][1]);
    }
}

int main()
{
    init();
    while (scanf("%d", &n) && n != -1)
    {
        printf("%d\n", ans[n]);
    }
    return 0;
}