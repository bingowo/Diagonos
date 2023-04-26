#include<stdio.h>
struct node
{
	long long a, cnt;
};
#define MAXN 10005
struct node a[MAXN];
int n;
void sort()
{
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 2; j <= n; ++j)
		{
			if(a[j - 1].cnt < a[j].cnt)
			{
				struct node c = a[j];
				a[j] = a[j - 1];
				a[j - 1] = c;
			}
			else if(a[j - 1].cnt == a[j].cnt && a[j - 1].a > a[j].a)
			{
				struct node c = a[j];
				a[j] = a[j - 1];
				a[j - 1] = c;
			}
		}
	}
}
int sov()
{
	scanf("%d", &n);
	memset(a, 0, sizeof(a));
	for(int i = 1; i <= n; ++i)
	{
		scanf("%lld", &a[i].a);
		for(int j = 0; j < 64; ++j)
		{
			a[i].cnt += ((a[i].a >> j) & 1);
		}
		printf("%d %d\n", a[i].a, a[i].cnt);
	}
	sort();
	for(int i = 1; i <= n; ++i)
		printf("%lld ", a[i].a);
	puts("");
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
	
}