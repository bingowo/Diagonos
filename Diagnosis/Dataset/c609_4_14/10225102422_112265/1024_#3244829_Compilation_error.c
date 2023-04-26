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
	if(strcmp(p1.day,p2.day)!=0)
	{
	    return strcmp(p1.day,p2.day);
	}
	else if(strcmp(p1.time,p2.time)!=0)
	return strcmp(p1.time,p2.time);
	else return strcmp(p1.name,p2.name);
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