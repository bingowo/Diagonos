#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct{
	char s[100001];
	char b[100001];
	int c[100];
}qwq;

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
		if(strlen(p[i].b)!=strlen(p[i+1].b)&&strcmp(p[i].b,p[i+1].b)!=0) 
		{
			printf("-1");
			return 0;
		} 
	}
	int an=0,anj=0;
	int len=strlen(p[0].b);
	for(int k=0;k<len;k++)
	{
		for(int j=0;j<t;j++)
		{
			an=0;
			for(int i=0;i<t;i++)
			{
				anj=an;
				an+=abs(p[i].c[k+1]-p[j].c[k+1]);//printf("an:%d\n",an);
			}
			if(anj>an) anj=an;//printf("%d\n",anj);
		}
		ans+=anj;
	}
	
	printf("%d\n",ans);
	
	
	return 0;
}