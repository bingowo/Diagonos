#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define min(a, b) (a > b ? b : a)
struct node
{
	int a[55];
	int n;
}a[105];
int cmp(const void *p1, const void *p2)
{
	node a = *(struct node*)p1;
	node b = *(struct node*)p2;
	int n = min(a.n, b.n);
	for(int i = 1; i <= n; ++i)
	{
		if(a.a[i] != b.a[i])
			return b.a[i] - a.a[i]; 
	}
	return b.n - a.n;
}
void sov()
{
	int n;
	memset(a, 0, sizeof(a));
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		int x;
		while(scanf("%d", &x))
		{
			if(x == -1)
				break;
			a[i].a[++a[i].n] = x;
		}
	}
	qsort(a + 1, n, sizeof(a[0]), cmp);
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= a[i].n; ++j)
		{
			printf("%d ", a[i].a[j]);
		}
		puts("");
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		sov();
	
}