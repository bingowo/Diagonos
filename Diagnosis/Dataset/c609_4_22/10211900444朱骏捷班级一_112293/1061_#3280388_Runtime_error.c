#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#define int long long
#define N 1010
bool vis[N];
int prime[N], num, dp[N], n;

void primes()
{
    for (int i = 2; i <= n; i++)
    {
        if (vis[i])
            continue;
        prime[++num] = i;
        for (int j = i; j * i <= n; j++)
            vis[j * i] = 1;
    }
}

int main()
{
    scanf("%d", &n);
    primes();
    dp[0] = 1;
    for (int i = 1; i <= num; i++)
        for (int j = prime[i]; j <= n; j++)
            dp[j] += dp[j - prime[i]];
    printf("%lld", dp[n]);
}