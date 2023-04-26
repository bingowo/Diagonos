#include <stdio.h>
#include <string.h>

const int MOD = 1000000007;
const int L = 210;
const int N = 1010;
int dp[N][N];
char s[N];

int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%s",s);
        int n = strlen(s);
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int pos = 0; pos < L; ++pos) {
                int tmp = 0;
                for (int j = i + 1; j <= n; ++j) {
                    tmp = (tmp * 10 + s[j - 1] - '0') % L;
                    dp[j][(pos + tmp) % L]=(dp[j][(pos + tmp) % L] + dp[i][pos]) % MOD;
                    dp[j][(pos + L - tmp) % L]=(dp[j][(pos + L - tmp) % L] + dp[i][pos]) % MOD;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < L; ++i)
            if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
                ans=(ans + dp[n][i]) %  MOD;
        //cout << ans / 2 << endl;
        printf("%lld\n",1LL * ans * ((MOD + 1) / 2) % MOD);
    }
}