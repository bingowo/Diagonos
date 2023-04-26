#include <stdio.h>
#include <stdlib.h>

int *get_v(int[], unsigned);
void put_ans(int[], int[], unsigned);
int acmp(const void *, const void *);

int main(void)
{
	unsigned n, i = 0;
	scanf("%d", &n);
	int v1[BUFSIZ], v2[BUFSIZ];
	while (n--) {
		printf("case #%d:\n", i++);
		unsigned m;
		scanf("%u", &m);
		put_ans(get_v(v1, m), get_v(v2, m), m);
		putchar('\n');
	}
	return 0;
}

int acmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

void put_ans(int x[], int y[], unsigned n)
{
	qsort(x, n, sizeof(x[0]), acmp);
	qsort(y, n, sizeof(y[0]), acmp);
	long ans = 0;
	for (unsigned i = 0; i < n; ++i)
		ans += x[i] * y[i];
	printf("%ld", ans);
}

int *get_v(int v[], unsigned n)
{
	int *t = v;
	for (unsigned i = 0; i < n; ++i)
		scanf("%d", &v[i]);
	return t;
}