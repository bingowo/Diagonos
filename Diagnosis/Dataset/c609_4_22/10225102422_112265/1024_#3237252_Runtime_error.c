#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 150
struct file
{
	char* name;
	int size;
	int year;
	int month;
	int day;
	char* time;
};
int year(char * s)
{
	int i = 0; int year=0;
	for (i = 0; s[i] != '-'; i++)
	{
		year = year * 10 + s[i] - '0';
	}
	return year;
}
int month(char * s)
{
	int i = 0; int month = 0;
	for (i = 0; s[i] != '-'; i++);
	for (i=i+1; s[i] != '-'; i++)
	{
		month = month * 10 + s[i] - '0';
	}
	return month;
}
int day(char * s)
{
	int i = 0; int day = 0;
	for (i = 0; s[i] != '-'; i++);
	for (i = i + 1; s[i] != '-'; i++);
	for (i = i + 1; s[i] != ' '; i++)
	{
		day = day * 10 + s[i] - '0';
	}
	return day;
}
char* time(char* s)
{
	int i;
	for (i = 0; s[i] != ' '; i++);
	int j = 0; char* time = (char*)malloc(sizeof(char)* 10);
	for (i = i + 1, j = 0; s[i] != ' '; i++, j++)
		time[j] = s[i];
	return time;
	
}
int size(char* s)
{
	int i = 0;
	for (i = 0; s[i] != ' '; i++);
	for (i = i + 1; s[i] != ' '; i++);
	for (; s[i] == ' '; i++);
	int size = 0;
	for (; s[i] != ' '; i++)
		size = size * 10 + s[i] - '0';
	return size;

}
char* name(char* s)
{
	int i = 0;
	for (i = 0; s[i] != ' '; i++);
	for (i = i + 1; s[i] != ' '; i++);
	for (; s[i] == ' '; i++);
	for (; s[i] != ' '; i++);
	char* name = (char*)malloc(sizeof(char)* 150);
	int j = 0;
	for (i = i + 1, j = 0; s[i] != '\n'; i++, j++)
		name[j] = s[i];
	return name;
}
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
	int n;
	scanf("%d", &n);
	int i;
	struct file* File = (struct file*)malloc(sizeof(struct file)*n);
	char s[N];
	for (i = 0; i < n; i++)
	{
		fgets(s, N, stdin);
		File[i].year = year(s);
		File[i].month = month(s);
		File[i].day = day(s);
		File[i].time = time(s);
		File[i].size = size(s);
		File[i].name = name(s);
	}
	char t[11];
	scanf("%s", t);
	int j; char L[5];
	for (j = 6; j < strlen(t); j++)
		L[j - 6] = t[j];
	L[j - 6] = '\0';
	if (!strcmp(L, "NAME"))
	{
		qsort(File, n, sizeof(File[0]), cmp_name);
	}
	else if(!strcmp(L, "TIME"))
	{
		qsort(File, n, sizeof(File[0]), cmp_time);
	}
	else if (!strcmp(L, "SIZE"))
	{
		qsort(File, n, sizeof(File[0]), cmp_size);
	}
	for (i = 0; i < n; i++)
	{
		printf("%d-%02d-%d ", File[i].year, File[i].month, File[i].day);
		printf("%s", File[i].time);
		printf("%16d ", File[i].size);
		printf("%s\n", File[i].name);
	}
	free(File);
	return 0;
}