#include <stdio.h>
#include <stdbool.h>

#define MAXN 10000

bool is_prime[MAXN + 1]; // 记录素数

void init() { // 预处理素数
    for (int i = 2; i <= MAXN; i++) {
        is_prime[i] = true;
    }
    for (int i = 2; i * i <= MAXN; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int dp[MAXN + 1]; // 记忆化数组

int solve(int n) { // 动态规划求解
    dp[0] = 1; // 初始值
    for (int i = 2; i <= n; i++) {
        for (int j = i; j >= 2; j--) {
            if (is_prime[j] && j <= i) {
                dp[i] += dp[i - j]; // 状态转移方程
            }
        }
    }
    return dp[n];
}

int main() {
    int n;
    scanf("%d", &n);
    init(); // 预处理素数
    int cnt = solve(n); // 动态规划求解
    printf("%d\n", cnt);
    return 0;
}