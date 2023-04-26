#include <stdio.h>
#include <string.h>
#define MAXN 20
#define state 100
typedef long long ll;

int shu[MAXN];

ll dp[MAXN][state];

ll dfs(int pos, int s1, int qh, int limit)
{
    if (pos < 0 && qh % 9 != 0)
        return 1;
    else if (pos < 0 && qh % 9 == 0)
        return 0;
    if (!limit && dp[pos][s1] != -1)
        return dp[pos][s1];
    int up = limit ? shu[pos] : 9;
    ll ans = 0;
    for (int i = 0; i <= up; i++)
    {
        if (i != 9)
            ans += dfs(pos-1, i, qh+i, limit && i == shu[pos]);
    }
    if (!limit)
        dp[pos][s1] = ans;
    return ans;
}

ll solve (ll x)
{
    int pos = 0;
    while (x)
    {
        shu[pos++] = x % 10;
        x /= 10;
    }
    return dfs(pos-1, shu[pos-1], 0, 1);
}

int main()
{
    ll le, ri;
    scanf("%lld %lld\n", &le, &ri);
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", solve(ri) - solve(le-1));
    return 0;
}