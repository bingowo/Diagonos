#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int count(char* s)
{
	int a[128]={0};
	int cnt=0;
	for(int i=0;s[i];++i)
	{
		a[s[i]]=1;
	}
	for(int i=0;i<128;i++)if(a[i])cnt++;
	return cnt;
}
int cmp(const void* a,const void* b)
{
	char *ax=(char**)a,*bx=(char**)b;
	if(count(ax)<count(bx))return 1;
	else if(count(ax)>count(bx))return -1;
	else return strcmp(ax,bx);
}
int main()
{
	int n;scanf("%d",&n);//问题数 
	for(int cnt=0;cnt<n;cnt++)
	{
		int c;scanf("%d",&c);//这个问题下字符串数
		char* a[c];//存储字符串 
		char *p;
		for(int i=0;i<c;i++) 
		{
			char *t=(char*)malloc(1005*sizeof(char));
			scanf("%s",t);
			p=t;
			a[i]=p;
		}
		qsort(a,c,sizeof(a[0]),cmp);
		printf("case #%d:\n",cnt);
		for(int i=0;i<c;i++)printf("%s\n",a[i]);
		for(int i=0;i<c;i++)free(a[i]);
	}
}