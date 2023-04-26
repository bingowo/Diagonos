#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 150
struct file
{
	unsigned char name[64];
	int size;
	char day[11];
	char time[10];
};
int cmp_time(const void* e1, const void* e2)
{
	struct file p1 = *(struct file*)e1;
	struct file p2 = *(struct file*)e2;
	int year1 = 0, month1 = 0, day1 = 0;
	int i = 0;
	for (i = 0; p1.day[i] != '-'; i++)
		year1 = year1 * 10 + p1.day[i] - '0';
	for (i = i + 1; p1.day[i] != '-'; i++)
		month1 = month1 * 10 + p1.day[i] - '0';
	for (i = i + 1; p1.day[i] != ' '; i++)
		day1 = day1 * 10 + p1.day[i] - '0';
	int year2 = 0, month2 = 0, day2 = 0;
	for (i = 0; p1.day[i] != '-'; i++)
		year2 = year2 * 10 + p1.day[i] - '0';
	for (i = i + 1; p1.day[i] != '-'; i++)
		month2 = month2 * 10 + p1.day[i] - '0';
	for (i = i + 1; p1.day[i] != ' '; i++)
		day2 = day2 * 10 + p1.day[i] - '0';
	if (year1 != year2)
		return year1 - year2;
	else
	{
		if (month1 != month2)
			return month1 - month2;
		else
		{
			if (day1 != day2)
				return day1 - day2;
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
	scanf("%d", &n);
	struct file s[120];
	int i = 0;
	char a[15];
	while (n != 0)
	{
		if (flag == 0) printf("\n");
		for (i = 0; i < n; i++)
		{
			scanf("%s %s %d %s", s[i].day,s[i].time,&s[i].size,s[i].name);
		}
		gets(a);
		gets(a);
		if (a[6] == 'N') qsort(s, n, sizeof(file), cmp_name);
		else if (a[6] == 'T') qsort(s, n, sizeof(file), cmp_time);
		else if (a[6] == 'S') qsort(s, n, sizeof(file), cmp_size);
		for (i = 0; i < n; i++)
			printf("%s %s %16d %s\n",s[i].day, s[i].time, s[i].size, s[i].name);
		flag = 0;
		scanf("%d", &n);
	}
	return 0;
}