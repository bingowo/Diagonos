#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{  int k,T;
	scanf("%d\n",&T);
	char re[]={"theaanofforand"};
	for(k=0;k<T;k++)
	{	 char s[101]={'\0'};
		gets(s);
		int co=0;
		char*p=s;
		while(*p==' ') p++;
		while(*p)
		{ char *q=p;
			for(;*q&&*q!=' ';q++);
			int l;
			char s1[20]={'\0'};
			for(l=0;l<q-p;l++,p++) s1[l]=*p;
			char*s2=strlwr(s1);
			if(strstr(re,s2)==0) co++;
			p++;
		}
		printf("case #%d:\n",k);
		printf("%d\n",co);
	}
	return 0;
}