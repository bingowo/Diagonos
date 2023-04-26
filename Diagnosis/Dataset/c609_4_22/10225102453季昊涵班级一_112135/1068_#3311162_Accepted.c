#include <stdio.h>


int  t, n, ans;

int solve(int p, int m) {
	if (m == 0) {
		if (p == t)
			ans++;
		return ans;
	}
	if (p == 1)
		solve(2, m - 1);
	else if (p == n)
		solve(n - 1, m - 1);
	else
		solve(p + 1, m - 1) + solve(p - 1, m - 1);

}

int main() {
	int cas, p, m;
	scanf("%d", &cas);
	while (cas--) {
		ans = 0;
		scanf("%d%d%d%d", &n, &p, &m, &t);
		printf("%d\n", solve(p, m));
	}
	return 0;
}