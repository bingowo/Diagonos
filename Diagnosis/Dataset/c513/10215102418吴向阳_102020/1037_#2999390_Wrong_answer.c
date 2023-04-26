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
	unsigned long long min = 0, temp;
	for (int i = 1; i < m; i++)
	{
		min += (a[i] - a[i-1]);
	}
	temp = min;
	for (int i = 2; i < n-m; i++)
	{
		temp = temp - (a[i-1] - a[i - 2]) + (a[i+m] - a[i+m-1]);
		if (temp < min) min = temp;
	}
	printf("%llu", min);
	free(a);
	return 0;
}