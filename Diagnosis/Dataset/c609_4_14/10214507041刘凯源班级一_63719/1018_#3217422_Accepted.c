#include<stdio.h>
#include<stdlib.h>
int a[100005];
int n;
int cmp(void *a, void *b)
{
	int *p1 = (int*)a, *p2 = (int*)b;
	return *p1 - *p2;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	qsort(a + 1, n, sizeof(a[0]), cmp);
//	for(int i = 1; i <= n; ++i)
//		printf("%d ", a[i]);
	int ans = 0;
	for(int i = 1; (i << 1) <= n; ++i)
	{
		ans += (a[2 * i] - a[2 * i - 1]);
	}
	printf("%d", ans);
}