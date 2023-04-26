#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int k=0;
typedef struct{
	char s[1000];
	char b[1000];
	int c[100];
}qwq;
int cmp(const void*a,const void*b)
{
	qwq*p1=(qwq*)a;qwq*p2=(qwq*)b;
	int l1=p1->c[k+1],l2=p2->c[k+1];
	if(l1>l2) return 1;
	else return -1;
}
int main()
{
	int t;
	scanf("%d",&t);
	qwq*p=(qwq*)malloc(t*sizeof(qwq));
	for(int i=0;i<t;i++)
	{
		for(int l=0;l<100;l++) p[i].c[l]=1;
		scanf("%s",p[i].s);
		int k=0;
		p[i].b[k++]=p[i].s[0];
		for(int j=1;j<strlen(p[i].s);j++)
		{
			if(p[i].s[j]!=p[i].s[j-1]) p[i].b[k++]=p[i].s[j];
			else p[i].c[k]++;
		}
		p[i].b[k]='\0';//printf("%d\n",p[i].c[1]);
	}
	int ans=0;
	for(int i=0;i<t-1;i++)
	{
		if(strlen(p[i].b)!=strlen(p[i+1].b)||strcmp(p[i].b,p[i+1].b)!=0) 
		{
			printf("-1");
			return 0;
		} 
	}
	int an=0,anj=0;
	int len=strlen(p[0].b);
	for(;k<len;k++)
	{//printf("len:%d\n",strlen(p[0].s));
		an=0;anj=3000000;
		qsort(p,t,sizeof(p[0]),cmp);
		printf(" %d %d\n",p[t-1].c[k+1],p[0].c[k+1]);
		for(int b=t/2;b<t/2+10&&b<t-1;b++)
		{
			an=0;
			for(int i=0;i<t;i++) an+=abs(p[i].c[k+1]-p[b].c[k+1]);//printf("%d\n",an);
			if(anj<an) an=anj;
		}
		
		ans+=an;
	}
	
	printf("%d\n",ans);
	
	
	return 0;
}