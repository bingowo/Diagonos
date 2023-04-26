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
	long long *b = (long long *)malloc ((n-1) * sizeof(long long));
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
	qsort(a, n, sizeof(a[0]), cmp);
	for (int i = 1; i < n; i++) b[i-1] = a[i] - a[i-1];
	if (m == 1) 
	{
		printf("%lld", 0);
		return 0;
	}
	unsigned long long min = 0, temp;
	for (int i = 0; i < m; i++)
	{
		min += (a[m-1] - a[i]);
	}
	temp = min;
	for (int i = 1; i < n-m; i++)
	{
		temp = temp + (m-1) * b[i+m-2];
		for (int j = i-1; j < i+m-2; j++) temp -= b[j];
		if (temp < min) min = temp;
	}
	printf("%llu", min);
	free(a);
	free(b);
	return 0;
}