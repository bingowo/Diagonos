#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
        int **dp = (int **)malloc(sizeof(int *) * (n + 1));
        for (int i = 0; i <= n; i++)
        {
            dp[i] = (int *)malloc(sizeof(int) * (m + 1));
            memset(dp[i], 0, (n + 1) * sizeof(int));
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < min(m + 1, i + 1); j++)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
        printf("%d\n", dp[n][m]);
        for (int i = 0; i <= n; i++)
            free(dp[i]);
        free(dp);
    }
    return 0;
}