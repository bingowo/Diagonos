#include <stdio.h>
#include <stdlib.h>

long long *get_v(long long[], unsigned);
void put_ans(long long[], long long[], unsigned);
int acmp(const void *, const void *);

int main(void)
{
	unsigned n, i = 0 ,m;
	scanf("%d", &n);
	long long v1[BUFSIZ], v2[BUFSIZ];
	while (n--) {
		scanf("%u", &m);
		printf("case #%d:\n", i++);
		put_ans(get_v(v1, m), get_v(v2, m), m);
		putchar('\n');
	}
	return 0;
}

int acmp(const void *a, const void *b)
{
	return *(long long *)a - *(long long *)b;
}

void put_ans(long long x[], long long y[], unsigned n)
{
	qsort(x, n, sizeof(x[0]), acmp);
	qsort(y, n, sizeof(y[0]), acmp);
	long long ans = 0;
	for (unsigned i = 0; i < n; ++i)
		ans += x[i] * y[n - i - 1];
	printf("%lld", ans);
}

long long *get_v(long long v[], unsigned n)
{
	int *t = v;
	for (unsigned i = 0; i < n; ++i)
		scanf("%lld", &v[i]);
	return t;
}