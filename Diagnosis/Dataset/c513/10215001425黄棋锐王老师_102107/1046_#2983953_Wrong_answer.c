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
	{	 char*s;
		s=(char*)malloc(101*sizeof(char));
		gets(s);
		int co=0;
		char*p=s;
		while(*p==' ') p++;
		while(*p)
		{ char *q=p;
			for(;*q&&*q!=' ';q++);
			int l;
			char s1[30]={'\0'};
			for(l=0;l<q-p;l++,p++) s1[l]=*p;
			lwr(s1);
			if(strstr(re,s1)==0) co++;
			p++;
		}
		printf("case #%d:\n",k);
		printf("%d\n",co);
	}
	return 0;
}