#include <stdio.h>
#define M 1001
#define N 10007
int main()
{
    int T, cnt = 0;
    scanf("%d", &T);
    while (T--)
    {
        printf("case #%d:\n", cnt++);
        int n, m, a, b, k;
        scanf("%d%d%d%d%d", &a, &b, &k, &n, &m);
        static int dp[M][M];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i + j)
                {
                    if (i == 0)
                        dp[i][j] = b * dp[i][j - 1] % N;
                    else if (j == 0)
                        dp[i][j] = a * dp[i - 1][j] % N;
                    else
                        dp[i][j] = (a * dp[i - 1][j] + b * dp[i][j - 1]) % N;
                }
            }
        }
        printf("%d\n", dp[n][m]);
    
    }
    return 0;
}