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
	for (int i = 0; i < m; i++)
	{
		min += (a[m-1] - a[i]);
	}
	for (int i = 1; i < n-m; i++)
	{
		temp = 0;
		for (int j = i;  j < i+m; j++)
		{
			temp += (a[j-1] - a[j]);
		}
		if (temp < min) min = temp;
	}
	printf("%llu", min);
	free(a);
	return 0;
}