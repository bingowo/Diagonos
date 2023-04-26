#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 105
#define indemo &a[i].time.year,&a[i].time.month,&a[i].time.day,&a[i].time.hour,&a[i].time.minute, &a[i].size, a[i].s
#define outdemo a[i].time.year,a[i].time.month,a[i].time.day,a[i].time.hour,a[i].time.minute, a[i].size, a[i].s
struct Time
{
	int day, month, year, hour, minute;
};
struct node
{
	struct Time time;
	int size;
	char s[65];	
}a[MAXN];
int cmp_name(const void *p1,const void* p2)
{
	struct node a, b;
	a = *(struct node*) p1;
	b = *(struct node*) p2;
	return strcmp(a.s, b.s);
}
int cmp_time(const void *p1,const void *p2)
{
	struct node a, b;
	a = *(struct node*) p1;
	b = *(struct node*) p2;
	if(a.time.year != b.time.year)
	{
		return a.time.year - b.time.year;
	}
	if(a.time.month != b.time.month)
	{
		return a.time.month - b.time.month;
	}
	if(a.time.day != b.time.day)
	{
		return a.time.day - b.time.day;
	}
	if(a.time.hour != b.time.hour)
	{
		return a.time.hour - b.time.hour;
	}
	if(a.time.minute != b.time.minute)
	{
		return a.time.minute - b.time.minute;
	}
	return strcmp(a.s, b.s);
}
int cmp_size(const void *p1,const void *p2)
{
	struct node a, b;
	a = *(struct node*) p1;
	b = *(struct node*) p2;
	if(a.size != b.size)
		return a.size - b.size;
	return strcmp(a.s, b.s);
}
void sov(int n)
{
	char demo[MAXN];
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d-%d-%d %d:%d %d %s",indemo);
	}
	scanf("%s", demo);
	scanf("%s", demo);
//	printf("%s", demo);
	if(!strcmp(demo, "/NAME"))
		qsort(a + 1, n, sizeof(struct node), cmp_name);
	else if(!strcmp(demo, "/TIME"))
		qsort(a + 1, n, sizeof(struct node), cmp_time);
	else if(!strcmp(demo, "/SIZE"))
		qsort(a + 1, n, sizeof(struct node), cmp_size);
	for(int i = 1; i <= n; ++i)
	{
		printf("%d-%d-%d %d:%d %16d %s\n",outdemo);
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("t.in", "r", stdin);
	freopen("t.out", "w", stdout);
#endif
	int n;
	while(scanf("%d", &n))
	{
		if(n == 0) break;
		sov(n);
		puts("");
	}
}