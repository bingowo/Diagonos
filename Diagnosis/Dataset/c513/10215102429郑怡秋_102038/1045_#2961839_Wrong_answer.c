#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct{
	char s[100001];
	char b[100001];
}qwq;

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
		p[i].b[k]='\0';//printf("%s\n%s",p[i].s,p[i].b);
	}
	for(int i=0;i<t-1;i++)
	{
		if(strcmp(p[i].b,p[i+1].b)!=1) 
		{
			printf("-1");
			return 0;
		 } 
	}
	
	
	
	
	return 0;
}