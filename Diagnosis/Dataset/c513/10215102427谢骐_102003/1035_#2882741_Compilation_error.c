#include <stdio.h>
#include <stdlib.h>

int cmp(const void *e1, const void *e2);

int main()
{
	int t, n;
	long long *a;
	scanf("%d", &t);

	for (int i = 0; i < t; ++i) {
		scanf("%d", &n);
		a = (long long *)malloc(t * sizeof(long long));

		for (int j = 0; j < n; ++j)
			scanf("%lld", a + j);

		qsort(a, n, sizeof(long long), cmp);
		printf("case #%d:\n", i);

		for (int j = 0; j < n; ++j)
			printf("%lld ", *(a + j));

		printf("\n");
	}

	return 0;
}

