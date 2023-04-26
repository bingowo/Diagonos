#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	int A = *(int *)a;
	int B = *(int *)b;
	return A - B;
}

int a[1001] = {0};
long long int b[500501] = {0};

int main() {
	int T;
	scanf("%d", &T);
	int f = 0;
	while (T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			scanf("%d", a + j);
			a[j] += a[j - 1];
		}
		for (int len = 1; len <= n; len++) {
			for (int i = 1; i <= n - len + 1; i++)
				b[++cnt] = a[i + len - 1] - a[i - 1];
		}
		qsort(b, cnt, sizeof(b[0]), cmp);
		for (int i = 1; i <= cnt; i++)
			b[i] += b[i - 1];
		printf("case #%d:\n", f++);
		for (int p = 0; p < m; p++) {
			int L, U;
			scanf("%d %d", &L, &U);
			printf("%lld\n", b[U] - b[L - 1]);
		}
	}



	return 0;
}