#include <string.h>

#define MAX_N 55

char s[MAX_N];
int dp[MAX_N];

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%s", s);
        int n = strlen(s);
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == '|') {
                if (i > 1 && s[i - 1] == '|') {
                    dp[i] = dp[i - 2] + 2;
                }
                else {
                    dp[i] = 0;
                }
            }
            else if (s[i] == '-') {
                if (i > 1 && s[i - 1] == '-') {
                    dp[i] = dp[i - 1];
                }
                else if (i > 2 && s[i - 2] == '|') {
                    dp[i] = dp[i - 2] + 2;
                }
                else {
                    dp[i] = 0;
                }
            }
            else {
                dp[i] = 0;
            }
            ans = ans > dp[i] ? ans : dp[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}