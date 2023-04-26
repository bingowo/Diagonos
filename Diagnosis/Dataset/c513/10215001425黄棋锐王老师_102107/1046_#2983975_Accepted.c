#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void lwr(char*s)
{ char*p=s;
	while(*p)
	{
		if('A'<=*p&&*p<='Z') *p='a'+*p-'A';
		p++;
	}
}
int main()
{  int k,T;
	scanf("%d\n",&T);
	char re[]={"theaanofforand"};
	for(k=0;k<T;k++)
	{	char s[101]={'\0'};
		gets(s);
		int co=0;
		char*p=s;
		while(*p)
		{ char *q=p;
		  char s1[30]={'\0'};
		  int l;
			for(l=0;*q&&*q!=' ';q++,l++) s1[l]=*q;
			lwr(s1);
			if(strstr(re,s1)==0) co++;
			p=++q;
		}
		printf("case #%d:\n",k);
		printf("%d\n",co);
	}
	return 0;
}