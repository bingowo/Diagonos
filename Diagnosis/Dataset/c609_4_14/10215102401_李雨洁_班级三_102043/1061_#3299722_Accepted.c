#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long dp[1001][1001];
int prime[1001];

int is_prime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}
int solve()
{
    int cnt = 0;
    for (int i = 2; i < 1001; i++)
    {
        if (is_prime(i))
            prime[++cnt] = i;
    }
    return cnt;
}
int main()
{
    int n;
    scanf("%d", &n);
    int np = solve();
    dp[0][0] = 1;
    int i;
    for (i = 1; i <= np && prime[i] <= n; i++)
    {
        for (int j = 0; j <= n; j++)
            dp[i][j] = dp[i - 1][j];
        for (int j = prime[i]; j <= n; j++)
        {
            for (int k = 1; k * prime[i] <= j; k++)
                dp[i][j] += dp[i - 1][j - k * prime[i]];
        }
    }
    printf("%lld\n", dp[i - 1][n]);
    return 0;
}
