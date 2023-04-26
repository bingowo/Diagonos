#include <stdio.h>
#include <stdlib.h>

int main() {
	int cmp(const void *a, const void *b);
	int T, N, i = 0, X;
	long long int num[10010];
	scanf("%d\n", &T);
	X = T;
	while (T-- > 1) {
		scanf("%d\n", &N);
		printf("case #%d:\n", X - T - 1);
		for (i = 0; i < N; i++)
			scanf("%lld", &num[i]);
		qsort(num, N, sizeof(num[0]), cmp);
		for (i = 0; i < N - 1; i++)
			printf("%lld ", num[i]);
		printf("%lld", num[i]);
		printf("\n");
		for (i = 0; i < 10010; i++)
			num[i] = 0;
	}
	printf("case #%d:\n", X-1);
	scanf("%d\n", &N);
	for (i = 0; i < N; i++)
		scanf("%lld", &num[i]);
	qsort(num, N, sizeof(num[0]), cmp);
	for (i = 0; i < N - 1; i++)
		printf("%lld ", num[i]);
	printf("%lld", num[i]);
}

int num1(long long int a) {
	int i, j = 0, sgn;
	sgn = (a > 0) ? 1 : (-1);
	for (i = 0; i < 64; i++) {
		j += a % 2;
		a >>= 1;
	}
	return (j * sgn);
}

int cmp(const void *a, const void *b) {
	int m = num1(*((long long int *)a));
	int n = num1(*((long long int *)b));
	if (m != n)
		return (n - m);
	else
		return ((*((long long int *)a) > *((long long int *)b)?1:(-1)));
}