#include<stdio.h>
#include<stdlib.h>
int cmp(const void* _a, const void* _b)
{
	int* a = (int*)_a;
	int* b = (int*)_b;
	return *a - *b;
}
int main()
{
	int t;
	scanf("%d", &t);
	int n, m,l, u;
	for (int z = 0; z < t; z++)
	{
		scanf("%d %d", &n, &m);
		int a[1001] = { 0 };
		long long int b[500501] = { 0 };
		int cnt = 0;
		for (int j = 1; j <= n; j++) 
		{ 
			scanf("%d", a + j);
			a[j] += a[j - 1];
		}
		for (int len = 1; len <= n; len++)
			for (int i = 1; i <= n - len + 1; i++)
				b[++cnt] = a[i + len - 1] - a[i - 1];
		qsort(b, cnt, sizeof(b[0]), cmp);
		for (int i = 1; i <= cnt; i++)
			b[i] += b[i - 1];
		printf("case #%d:\n", z);
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &l, &u);
			printf("%lld\n", b[u] - b[l - 1]);
		}
	}
	return 0;
}