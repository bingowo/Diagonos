#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	long long *p = (long long *)a, *q = (long long *)b;
	if (p - q >= 0) return 1;
	else return -1;
}

int main()
{
	long long m,n;
	scanf ("%lld%lld", &m, &n);
	long long *a = (long long *)malloc (n * sizeof(long long));
	for (int i = 0; i < n; i++) scanf("%lld", 0);
	qsort(a, n, sizeof(a[0]), cmp);
	if (m == 0) 
	{
		printf("%lld",a[0]);
		return 0;
	}
	long long max = 0;
	for (int i = 0; i < m-1; i++)
	{
		max += (a[m-1] - a[i]);
	}
	printf("%lld", max);
	free(a);
	return 0;
}