#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct { char s[22]; int num; }str;

int count_char(char p[])
{
	int table[128]={0};
	int len = strlen(p),count = 0;
	for(int i=0;i<len;i++)
	{
		if(table[p[i]] == 0)
			table[p[i]]++,count++;
		else
			table[p[i]]++;
	}
	return count;
}

int cmp(const void *a,const void *b)
{
	str m = *(str*)a, n = *(str*)b;
	if(m.num == n.num)
		return strcmp(m.s,n.s);
	else
		return n.num - m.num;
}
int main()
{
	int t;
	scanf("%d",&t);
	
	for(int i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		str *p = (str*)calloc(n,sizeof(str));
		
		for(int i=0;i<n;i++)
		{
			scanf("%s",p[i].s);
			p[i].num = count_char(p[i].s);
//			printf("num = %d\n",p[i].num);
		}
		qsort(p,n,sizeof(str),cmp);
		
		printf("case #%d:\n",i);
		for(int i=0;i<n;i++)
		{
			printf("%s\n",p[i].s);
		}
	}
	return 0;
}