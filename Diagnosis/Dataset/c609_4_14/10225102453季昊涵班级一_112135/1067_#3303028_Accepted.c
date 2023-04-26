#include <stdio.h>

int main() {
	int a, n, m, x;
	scanf("%d %d %d %d", &a, &n, &m, &x);
	int a_up[21], a_now[21], t_up[21], t_now[21];
	a_up[1] = 1;
	a_up[2] = 0;
	a_now[1] = 1;
	a_now[2] = 1;
	t_up[1] = 0;
	t_up[2] = 1;
	t_now[1] = 0;
	t_now[2] = 0;
	for (int i = 3; i <= n; i++) {
		a_up[i] = a_up[i - 1] + a_up[i - 2];
		t_up[i] = t_up[i - 1] + t_up[i - 2];
		a_now[i] = a_now[i - 1] + a_up[i - 2];
		t_now[i] = t_now[i - 1] + t_up[i - 2];
	}
	int t = (m - a_now[n - 1] * a) / t_now[n - 1];
	printf("%d", t * t_now[x] + a * a_now[x]);

	return 0;
}