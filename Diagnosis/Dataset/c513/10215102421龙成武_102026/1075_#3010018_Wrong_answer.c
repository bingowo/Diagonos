#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int** a;
long long dp[201][201];
long long mymin(long long a, long long b)
{
    return a < b ? a : b;
}
long long func(int m, int n)
{
    if (dp[m][n] == -1)
    {
        if (m == 0 && n == 0)
            dp[m][n] = a[0][0];
        else if (m == 0)
            dp[m][n] = func(m, n - 1) + a[m][n];
        else if (n == 0)
            dp[m][n] = func(m - 1, n) + a[m][n];
        else
            dp[m][n] = mymin(func(m - 1, n), func(m, n - 1)) + a[m][n];
    }
    return dp[m][n];
}
int main()
{
    int M, N, i, j;
    scanf("%d%d", &M, &N);
    a = (int**)malloc(M * sizeof(int*));
    for (i = 0;i < M;i++)
    {
        a[i] = (int*)malloc(N * sizeof(int));
        for (j = 0;j < N;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    memset(dp, -1, sizeof(dp));
    printf("%lld", func(M - 1, N - 1));
    return 0;
}
