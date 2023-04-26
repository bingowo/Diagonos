#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{int begin;int end;} index;

int cmp(const void* a,const void* b)
{
	char *p1=*(char**)a,*p2=*(char**)b;
	return strcmp(p1,p2);
}

int main()
{
	int T;scanf("%d\n",&T);
	int i,j;
	char s[510];
	for(i=0;i<T;i++)
	{
		gets(s);
		int cnt=0,flag=1;
		for(j=0;j<strlen(s);j++)
		{
			if(s[j]==' '||s[j]==','||s[j]=='.'||s[j]=='!'||s[j]=='?')
				{if(flag){flag=0;cnt++;}}
			else if(!flag)flag=1;
		}
		//printf("cnt=%d\n",cnt);
		
		index a[cnt];flag=1;
		int k=0;a[k].begin=0;
		for(j=0;j<strlen(s);j++)
		{
			if(s[j]==' '||s[j]==','||s[j]=='.'||s[j]=='!'||s[j]=='?')
			{
				if(flag)
				{
					a[k].end=j-1;
					k++;
					flag=0;
				}
			}
			else if(!flag)
			{
				flag=1;
				a[k].begin=j;
			}
		}
		//for(j=0;j<cnt;j++)printf("%d %d\n",a[j].begin,a[j].end);
		
		char **b=(char**)malloc(sizeof(char*)*cnt);
		for(j=0;j<cnt;j++)
		{
			char *c=(char*)malloc(sizeof(char)*(a[j].end-a[j].begin+2));
			int p=0;
			for(k=a[j].begin;k<=a[j].end;k++)c[p++]=s[k];
			c[p]=0;
			b[j]=c;
		}
		
		qsort(b,cnt,sizeof(char*),cmp);
		
		printf("case #%d:\n",i);
		if(cnt==0)printf("%s",s);
		for(j=0;j<cnt;j++)
		{
			if(j==0)printf("%s ",b[j]);
			else
			{
				int flag=1;
				for(int p=0;p<j;p++)
				{
					if(strcmp(b[p],b[j])==0)
					{
						flag=0;
						break;
					}
				}
				if(flag)printf("%s ",b[j]);
			}
		}
		printf("\n");
		
		
		for(j=0;j<cnt;j++)
			free(b[j]);
		free(b);
		
	}
	return 0;
}