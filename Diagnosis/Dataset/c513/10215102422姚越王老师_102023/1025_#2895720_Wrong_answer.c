#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int count(char* s)
{
	char store[strlen(s)];
	for(int i=0;i<strlen(s);i++)
	{
		if(i==0){store[i]=s[i];store[1]=0;}
		else
		{
			int j,flag=1;
			int length=strlen(store);
			for(j=0;j<length;j++)
			{
				if(store[j]==s[i])flag=0;
			}
			if(flag){store[length]=s[i];store[length+1]=0;}
		}
	}
	return strlen(store);
}
int cmp(const void* a,const void* b)
{
	char *ax=(char*)a,*bx=(char*)b;
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