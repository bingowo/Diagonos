#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long LL;

bool mark[1005];
LL dp[1500], prime[1005], n, num;

LL max(LL a, LL b) { return a > b ? a : b; }

int main()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        if (mark[i] == false)
            prime[num++] = i;
        for (int j = 0; j < num && prime[j] * i <= n; j++)
        {
            mark[prime[j] * i] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
    dp[0] = 1;
    for (int i = 0; i < num; i++)
        for (int j = prime[i]; j <= n; j++)
            dp[j] += dp[j - prime[i]];
    printf("%lld", dp[n]);
    return 0;
}