#include <stdio.h>
#include <math.h>

void solve() {
    int n, p, m, t;
    scanf("%d%d%d%d", &n, &p, &m, &t);
    if (((int)fabs(p - t) & 1) != (m & 1)) {
        printf("0\n");
        return ;
    }


    int dp[n+1][m+1];
    
    for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= n; ++j)
            dp[j][i] = 0;

    dp[p][0] = 1;
    for (int i = 1; i <= m; ++i) {  // time
        for (int j = 1; j <= n; ++j) {  // building
            if (j == 1 && n != 1)
                dp[j][i] = dp[j+1][i-1];
            else if (j == n)
                dp[j][i] = dp[j-1][i-1];
            else
                dp[j][i] = dp[j+1][i-1] + dp[j-1][i-1];
        }
    }
    printf("%d\n", dp[t][m]);
}
int main() {
    int n;
    scanf("%d", &n);
    while(n--)
        solve();
    return 0;
}