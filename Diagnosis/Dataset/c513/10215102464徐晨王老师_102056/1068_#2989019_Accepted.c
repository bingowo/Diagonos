#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int dp[35];
int main()
{
    int n,m;
    while (~scanf("%d %d", &n, &m))
    {
        if (n == -1 && m == -1) break;
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (i < m) dp[i] = 2 * dp[i-1];
            else if (i == m) dp[i] = 2 * dp[i-1] - 1;
            else dp[i] = 2 * dp[i-1] - dp[i-m-1];
        }
        printf("%d\n",(int)pow(2,n) - dp[n]);
    }
    return 0;
}
