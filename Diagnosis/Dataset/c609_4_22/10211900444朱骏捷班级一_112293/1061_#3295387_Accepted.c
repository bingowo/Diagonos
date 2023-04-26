#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define ll long long
#define MAXN 1010
ll vis[MAXN], dp[MAXN];

int main()
{
    ll n, q;
    scanf("%lld", &n);
    dp[0] = 1;
    vis[1] = 1;
    for (ll i = 2; i <= sqrt(n); i++)
    {
        if (vis[i] == 0)
            for (ll j = i * i; j <= n; j = j + i)
                vis[j] = 1;
    }
    for (ll i = 2; i <= n; i++)
        if (vis[i] == 0)
            for (ll j = i; j <= n; j++)
                dp[j] += dp[j - i];
    printf("%lld", dp[n]);
    return 0;
}