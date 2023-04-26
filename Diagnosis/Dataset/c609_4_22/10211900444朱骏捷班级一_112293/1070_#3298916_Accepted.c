#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ll long long
#define ull unsigned long long
#define MAXN 10010
// DP[i] = 2 * DP[i - 1] - (DP[i - 2] - DP[i - 3]);

int main()
{
    int dp[MAXN] = {0, 2, 4, 7};
    int n;
    while (scanf("%d", &n) && n != -1)
    {
        for (int i = 4; i < MAXN; i++)
            dp[i] = (2 * dp[i - 1] - (dp[i - 2] - dp[i - 3]));
        printf("%llu\n", dp[n]);
    }
    return 0;
}