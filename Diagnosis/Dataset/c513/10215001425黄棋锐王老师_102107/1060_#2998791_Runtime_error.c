#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int di(char c)
{
	if('1'<=c&&c<='9') return 1;
	else return 0;
}
int main()
{    char s[200]={'\0'};
	gets(s);
	int l=0;
	char *p;
	char*q;
	while(di(*p)==0) p++;
	while(*p)
	{   q=p;
	   while(*q&&di(*q)==1) q++;
		int t=q-p;
		if(t>l) l=t;
		p=q;
		while(*p&&di(*p)==0) p++;
	}
	printf("%d",l);
	return 0;
}

