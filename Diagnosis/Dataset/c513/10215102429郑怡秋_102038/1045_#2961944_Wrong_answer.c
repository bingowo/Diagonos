#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct{
	char s[100001];
	char b[100001];
}qwq;
int cmp(const void*a,const void*b)
{
	qwq*p1=(qwq*)a;qwq*p2=(qwq*)b;
	return abs(strlen(p1->s)-strlen(p2->s));
}
int main()
{
	int t;
	scanf("%d",&t);
	qwq*p=(qwq*)malloc(t*sizeof(qwq));
	for(int i=0;i<t;i++)
	{
		scanf("%s",p[i].s);
		int k=0;
		p[i].b[k++]=p[i].s[0];
		for(int j=1;j<strlen(p[i].s);j++)
		{
			if(p[i].s[j]!=p[i].s[j-1]) p[i].b[k++]=p[i].s[j];
		}
		p[i].b[k]='\0';printf("%s\n%s\n",p[i].s,p[i].b);
	}
	qsort(p,t,sizeof(p[0]),cmp);
	int ans=0;
	for(int i=0;i<t-1;i++)
	{
		if(strcmp(p[i].b,p[i+1].b)!=0) 
		{
			printf("-1");
			return 0;
		 } 
		ans+=strlen(p[i].s);
	}
	ans+=strlen(p[t-1].s);
//	int x1=strlen(p[t-1].s),x0=strlen(p[0].s);
//	
	printf("%d\n",ans/2);
	
	
	return 0;
}