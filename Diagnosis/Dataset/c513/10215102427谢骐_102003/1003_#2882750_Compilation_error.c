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

{
	long long mask = 1, n1 = *(long long *)e1, n2 = *(long long *)e2;
	int m1 = 0, m2 = 0;

	for(int i = 0; i < 64; ++i) {
		if (n1 & mask)
			++m1;

		mask = mask << 1;
	}

	mask = 1LL;

	for (int i = 0; i < 64; ++i) {
		if (n2 & mask)
			m2++;

		mask = mask << 1;
	}

	if (m1 != m2)
		return m2 - m1;
	else
		return n1 - n2;
}
