#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int dp[21][101];
int getit(int n, int p, int m, int t)
{
    if (m == 0)
    {
        if (t == p)
            dp[m][t] = 1;
        else
            dp[m][t] = 0;
    }
    else if (dp[m][t] == -1)
    {
        dp[m][t] = 0;
        if (t > 1)
            dp[m][t] += getit(n, p, m - 1, t - 1);
        if (t < n)
            dp[m][t] += getit(n, p, m - 1, t + 1);
    }
    return dp[m][t];
}
int main()
{
    int cas, n, p, m, t;
    scanf("%d", &cas);
    while (cas--)
    {
        memset(dp, -1, sizeof(dp));
        scanf("%d%d%d%d", &n, &p, &m, &t);
        printf("%d\n", getit(n, p, m, t));
    }
    return 0;
}

