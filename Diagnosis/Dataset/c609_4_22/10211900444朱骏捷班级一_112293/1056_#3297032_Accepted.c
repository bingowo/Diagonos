#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ull unsigned long long

int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int z = 0; z != t; z++)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        printf("case #%d:\n", z);
        ull **dp = (ull **)malloc(sizeof(ull *) * (n + 1));
        for (int i = 0; i <= n; i++)
        {
            dp[i] = (ull *)malloc(sizeof(ull) * (m + 1));
            memset(dp[i], 0, (m + 1) * sizeof(ull));
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < min(m + 1, i + 1); j++)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
        printf("%llu\n", dp[n][m]);
        for (int i = 0; i <= n; i++)
            free(dp[i]);
        free(dp);
    }
    return 0;
}