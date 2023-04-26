#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *_a, const void *_b){
	long long *a = (long long *)_a;
	long long *b = (long long *)_b;
	long long p = *a;
	long long q = *b;
	long long m, n;
	m = n = 0;
	
	while (p){
		m = p;
		p /= 10;
	}
	while (q){
		n = q;
		q /= 10;
	}
	
	if (m < 0)
		m = -m;
	if (n < 0)
		n = -n;

	if (m != n)
		return n - m;

	if (*a > *b)
		return 1;
	return -1;
}

int main()
{
	int ncase, T, i, j, k;
	scanf("%d",&ncase);
	for (T = 0; T < ncase; T++) {
		int n;
		scanf("%d", &n);
		long long s[n];
		for (i = 0; i < n; i++)
			scanf("%lld", &s[i]);

		qsort(s, n, sizeof(s[0]), cmp);
		
		printf("case #%d:\n", T);
		for (i = 0; i < n - 1; i++)
			printf("%lld ", s[i]);
		printf("%lld\n", s[i]);
	}
	return 0;
}