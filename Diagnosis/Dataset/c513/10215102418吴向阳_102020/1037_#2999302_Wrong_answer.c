#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int cmp(const void *p, const void *q)
{
	long long *p1 = (long long *)p, *p2 = (long long *)q;
	if (*p1 - *p2 >= 0) return 1;
	else return -1;
}

int main()
{
	long long m,n;
	scanf ("%lld%lld", &n, &m);
	long long *a = (long long *)malloc (n * sizeof(long long));
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
	qsort(a, n, sizeof(a[0]), cmp);
	if (m == 1) 
	{
		printf("%lld", 0);
		return 0;
	}
	unsigned long long max = 0;
	long long address = 0, min = a[m-1] - a[0];
	for (int i = 1; i < n-m+1; i++)
	{
		if (a[i+m-1] - a[i] < min)
		{
			address = i;
			min = a[i+m-1] - a[i];
		}
	}
	for (int i = address; i < address+m-1; i++)
	{
		max += (a[address+m-1] - a[i]);
	}
	printf("%llu", max);
	free(a);
	return 0;
}