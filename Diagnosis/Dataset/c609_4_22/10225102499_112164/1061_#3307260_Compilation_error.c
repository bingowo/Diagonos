#include <iostream>
#include <vector>

using namespace std;

int ck_prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)
			return 0;
	}
	return 1;
}

int sieve(vector<int> &prime) {
	int cnt = 0;
	for (int i = 2; i < 1005; i++) {
		if (ck_prime(i))
			prime[cnt++] = i;
	}
	return cnt;
}

int main() {
	int n;
	vector<long long> dp(1005);
	vector<int> prime(1005);
	cin >> n;
	int np = sieve(prime);
	dp[0] = 1;
	for (int i = 0; i < np && prime[i] <= n; i++) {
		for (int j = prime[i]; j <= n; j++) {
			dp[j] += dp[j - prime[i]];
		}
	}
	cout << dp[n] << endl;
	return 0;
}
