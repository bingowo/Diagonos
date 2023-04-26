#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
typedef struct{
	char s[20];
	int cnt;
}STR;
int cmp(const void* a,const void* b)
{
	STR x=*(STR*)a;STR y=*(STR*)b;
	if(x.cnt==y.cnt)
	{
		return strcmp(x.s,y.s);
	}
	if(x.cnt<y.cnt)return -1;
	else return 1;
}
int main()
{
	STR a[200001],b[200001];
	int n,ct=0;scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",a[i].s);
		a[i].cnt=0;
	}
	qsort(a+1,n,sizeof(STR),cmp);
	int x=1;
	for(int i=1;i<=n;i++)
	{
		if(i==1||strcmp(a[i].s,a[i-1].s)!=0)
		{
			b[ct].cnt=x;x=1;
			strcpy(b[++ct].s,a[i].s);
		}
		else x++;
	}
	b[ct].cnt=x;
	qsort(b+1,ct,sizeof(STR),cmp);
	for(int i=1;i<=ct;i++)
	{
		printf("%s",b[i].s);
		if(i!=ct)printf("\n");
	}
	return 0;
}