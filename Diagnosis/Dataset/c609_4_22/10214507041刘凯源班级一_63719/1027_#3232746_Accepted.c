#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXN 510
#define MAXM 15
int a[MAXM];
struct node
{
	int score;
	char s[15];
}stu[MAXN];
int n, m, g;
int cmp(const void *p1, const void *p2)
{
	struct node a,b;
	a = *(struct node*)p1;
	b = *(struct node*)p2;
	return a.score == b.score ? strcmp(a.s, b.s) : b.score - a.score;
}
void sov()
{
	memset(stu, 0, sizeof(stu));
	
	scanf("%d %d %d", &n, &m, &g);
	for(int i = 1; i <= m; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%s", stu[i].s);
		int s;
		scanf("%d", &s);
		for(int j = 1; j <= s; ++j)
		{
			int x;
			scanf("%d", &x);
			stu[i].score += a[x];
		}
	}
	qsort(stu + 1, n, sizeof(struct node), cmp);
	int ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		if(stu[i].score >= g)
			++ans;
	}
	printf("%d\n", ans);
	for(int i = 1; i <= ans; ++i)
	{
		printf("%s %d\n", stu[i].s, stu[i].score);
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
}