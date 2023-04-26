#include <stdio.h>

long long int f(int n) {
	if (n <= 2)
		return n;
	long long int dp[n + 1];
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
	}
	return dp[n];



}

int main() {
	int T;
	scanf("%d", &T);
	int k = 0;
	while (T--) {
		int n;
		scanf("%d", &n);
		printf("case #%d:\n", k++);
		printf("%lld\n", f(n));
	}
	return 0;
}