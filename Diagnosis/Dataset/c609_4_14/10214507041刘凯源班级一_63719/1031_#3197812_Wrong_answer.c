#include<stdio.h>
#include<stdlib.h>
#define MAXN 1000005
int a[MAXN];
long long b[MAXN], tot;
long long suma[MAXN];
long long sumb[MAXN];
int n, m, u, l;
void st(int l, int r)
{
	int mid = b[(l + r) / 2];
	int i = l, j = r;
	do
	{
		while(b[i] < mid) ++i;
		while(b[j] > mid) --j;
		if(i <= j)
		{
//			swap(b[i], b[j]);
			int c = b[j];
			b[j] = b[i];
			b[i] = c;
			++i, --j;
		}
	}while(i <= j);
	if(l < j)
		st(l, j);
	if(i < r)
		st(i, r);
}
void sov()
{
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i)
		suma[i] = suma[i - 1] + a[i];
	tot = 0;
	for(int len = 1; len <= n; ++len)
	{
		for(int l = 1; l + len - 1 <= n; ++l)
		{
			b[++tot] = suma[l + len - 1] - suma[l - 1];
		}
	}
	st(1, tot);
	for(int i = 1; i <= tot; ++i)
		sumb[i] = sumb[i - 1] + b[i];
	for(int i = 1; i <= m; ++i)
	{
		scanf("%d %d", &l, &u);
		printf("%d\n", sumb[u] - sumb[l - 1]);
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i)
	{
		printf("case #%d:\n", i);
		sov();
	}
	return 0;
}