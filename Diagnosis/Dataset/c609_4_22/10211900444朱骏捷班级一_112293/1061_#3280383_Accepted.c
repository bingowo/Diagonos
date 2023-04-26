#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxn 1010

long long dp[maxn], v[maxn];

int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 2; i <= maxn; i++)
    {
        int flag = 0;
        for (int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            v[cnt++] = i;
    }
    dp[0] = 1;
    for (int i = 0; i < cnt; i++)
    {
        for (int j = v[i]; j <= n; j++)
        {
            dp[j] += dp[j - v[i]];
        }
    }
    printf("%lld", dp[n]);
    return 0;
}