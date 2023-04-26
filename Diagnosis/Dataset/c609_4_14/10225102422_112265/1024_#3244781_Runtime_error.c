#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct file
{
	char name[64];
	int size;
	int year;
	int month;
	int day;
	char time[10];
};
int cmp_time(const void* e1, const void* e2)
{
	struct file p1 = *(struct file*)e1;
	struct file p2 = *(struct file*)e2;
	if (p1.year != p2.year)
		return p1.year - p2.year;
	else
	{
		if (p1.month != p2.month)
			return p1.month - p2.month;
		else
		{
			if (p1.day != p2.day)
				return p1.day - p2.day;
			else return strcmp(p1.time, p2.time);
		}
	}
}
int cmp_size(const void* e1, const void* e2)
{
	struct file p1 = *(struct file*)e1;
	struct file p2 = *(struct file*)e2;
	return p1.size - p2.size;
}
int cmp_name(const void* e1, const void* e2)
{
	struct file p1 = *(struct file*)e1;
	struct file p2 = *(struct file*)e2;
	return strcmp(p1.name, p2.name);
}
int main()
{
	int n, flag = 1;
	scanf("%d\n", &n);
	struct file s[120];
	int i = 0;
	char a[15];
	while (n != 0)
	{
		if (flag == 0) printf("\n");
		for (i = 0; i < n; i++)
		{
			scanf("%d-%d-%d", s[i].year, s[i].month, s[i].day);
			scanf("%s", s[i].time);
			scanf("%d", s[i].size);
			scanf("%s", s[i].name);
		}
		gets(a);
		gets(a);
		if (a[6] == 'N') qsort(s, n, sizeof(s[0]), cmp_name);
		else if (a[6] == 'T') qsort(s, n, sizeof(s[0]), cmp_time);
		else if (a[6] == 'S') qsort(s, n, sizeof(s[0]), cmp_size);
		for (i = 0; i < n; i++)
			printf("%d-%02d-%d %s%16d %s\n", s[i].year, s[i].month, s[i].day, s[i].time, s[i].size, s[i].name);
		flag = 0;
		scanf("%d\n", &n);
	}
	return 0;
}