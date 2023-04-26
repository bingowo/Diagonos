#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
typedef struct{
	char st[35];
	int NUM,LEN,flag;
}STR;
int cmp(const void* a,const void* b)
{
	STR x=*(STR*)a;STR y=*(STR*)b;
	if(x.flag==0&&y.flag==1)return -1;
	if((x.flag==0&&y.flag==0)||x.NUM==y.NUM)return strcmp(x.st,y.st);
	return x.NUM-y.NUM;
}
int main()
{
	int n=0;STR str[105];
	while(scanf("%s",str[n].st)!=EOF)
	{
		int len=strlen(str[n].st);
		int x=0;str[n].flag=0;
		for(int i=0;i<len;i++)
		{
			if(str[n].st[i]>='0'&&str[n].st[i]<='9')
			{
				str[n].flag=1;
				x=x*10+str[n].st[i]-'0';
			}
		}
		if(str[n].flag)str[n].NUM=x;else str[n].NUM=-1;str[n].LEN=len;n++;
	}
	qsort(str,n,sizeof(STR),cmp);
	for(int i=0;i<n;i++)
	{
		printf("%s",str[i].st);
		if(i!=n-1)printf(" ");
	}
	return 0;
}