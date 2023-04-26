#include <stdio.h>
#include <stdlib.h>

int count, t, n;

void level(int p, int m) {
	if (m == 0) {
		if (p == t)
			count++;
		return;
	}
	if (p == 1)
		level(2, m - 1);
	else if (p == n)
		level(n - 1, m - 1);
	else {
		level(p + 1, m - 1);
		level(p - 1, m - 1);
	}
}

int main() {
	int cas, start, min;
	scanf("%d", &cas);
	while (cas--) {
		count = 0;
		scanf("%d%d%d%d", &n, &start, &min, &t);
		level(start, min);
		printf("%d\n", count);
	}
	return 0;
}