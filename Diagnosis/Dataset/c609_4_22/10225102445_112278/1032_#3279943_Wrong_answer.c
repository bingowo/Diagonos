#include <stdio.h>
#include <string.h>

#define MAX_LEN 100001

int dp[MAX_LEN];

int main() {
    char s[MAX_LEN];
    scanf("%s", s);
    int n = strlen(s);
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == '|') {
            if (s[i - 1] == '|') dp[i] = 0;
            else dp[i] = dp[i - 2] + 2;
        } else if (s[i] == '-') {
            if (s[i - 1] == '-' || i < 2 || s[i - 2] != '|') dp[i] = 0;
            else dp[i] = dp[i - 2] + 2;
        } else {
            dp[i] = 0;
        }
        ans = ans > dp[i] ? ans : dp[i];
    }
    printf("%d\n", ans);
    return 0;
}