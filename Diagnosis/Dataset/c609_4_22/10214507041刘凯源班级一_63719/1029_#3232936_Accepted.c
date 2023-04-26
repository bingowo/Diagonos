#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 1005
int id[MAXN];
int a[MAXN];
int b[MAXN];
int n, m;
int cmp(const void *p1, const void *p2)
{
	int a = *(int*)p1;
	int b = *(int*)p2;
	return id[a] == id[b] ? a - b : id[a] - id[b];
}
int main()
{
	memset(id, 0x3f, sizeof(id));
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i)
	{
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= m; ++i)
	{
		id[a[i]] = i;
	}
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &b[i]);
	}
	qsort(b + 1, n, sizeof(b[0]), cmp);
	for(int i = 1; i <= n; ++i)
		printf("%d ", b[i]);
}