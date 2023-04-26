#include <stdio.h>

long long int solve(int n, int m) {
	long long int dp[33] = {0};
	for (int i = 1; i < m; i++)
		dp[i] = (1 << i);
	dp[m] = (1 << m) - 1;
	for (int j = m + 1; j <= n; j++) {
		for (int k = 1; k <= m; k++)
			dp[j] += dp[j - k];
	}
	long long int ans = (1U << n) - dp[n];
	return ans;
}

int main() {
	int n, m;
	while (scanf("%d %d", &n, &m)) {
		if (n == -1 && m == -1)
			break;
		else {
			printf("%lld\n", solve(n, m));
		}
	}
	return 0;
}