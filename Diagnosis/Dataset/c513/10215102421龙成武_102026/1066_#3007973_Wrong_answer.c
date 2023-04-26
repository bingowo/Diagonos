#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int dp[21][101];
int getit(int t, int tim, int p, int n)
{
    if (tim == 0)
    {
        if (p == t)
            dp[0][p] = 1;
        else
            dp[0][p] = 0;
    }
    else if (dp[tim][p] == -1)
    {
        dp[tim][p] = 0;   //表示这个方案已经被算过
        if (p > 1)
            dp[tim][p] += getit(t, tim + 1, p - 1, n);
        if (p < n)
            dp[tim][p] += getit(t, tim + 1, p + 1, n);
    }
    return dp[tim][p];
}
int main()
{
    int cas, n, p, m, t, ans;
    scanf("%d", &cas);
    while (cas--)
    {
        memset(dp, -1, sizeof(dp));
        scanf("%d%d%d%d", &n, &p, &m, &t);
        ans = getit(t, m, p, n);
        printf("%d\n", ans);
    }
    return 0;
}
