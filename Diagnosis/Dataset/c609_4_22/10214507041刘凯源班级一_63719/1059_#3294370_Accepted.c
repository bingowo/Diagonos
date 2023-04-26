#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	char s[105];
	double num;
};
struct node a[105];
int n;
int cmp(const void *p1, const void *p2)
{
	struct node a, b;
	a = *(struct node*)p1;
	b = *(struct node*)p2;
	return (a.num - b.num < 0) ? -1 : 1;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%s", a[i].s);
		a[i].num = atof(a[i].s);
	}
	qsort(a + 1, n, sizeof(a[0]), cmp);
	for(int i = 1; i <= n; ++i)
	{
		puts(a[i].s);
	}
}