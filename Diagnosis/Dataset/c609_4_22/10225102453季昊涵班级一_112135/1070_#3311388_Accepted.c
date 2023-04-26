#include <stdio.h>

int solve(int t) {
	int f[21], g[21];
	f[0] = g[0] = 0, f[1] = g[1] = 1;
	for (int i = 2; i <= 20; i++) {
		f[i] = f[i - 1] + g[i - 1];
		g[i] = f[i] - g[i - 2];
	}
	return f[t] + g[t];
}

int main() {
	int t;
	while (scanf("%d", &t)) {
		if (t == -1)
			break;
		else
			printf("%d\n", solve(t));

	}
	return 0;
}