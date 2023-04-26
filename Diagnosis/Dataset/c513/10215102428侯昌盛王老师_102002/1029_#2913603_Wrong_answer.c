#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*a,const void*b)
{
	char *q,*p;
	q=(char*)a;
	p=(char*)b;
	if(*q>='A' && *q<='Z' && *p>='A' && *p<='Z')
	{
		
		if(*q<*p) return -1;
		else if(*q>*p) return 1;
		else return 0;
	}
	else return 0;

 } 

int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		char str[201];
	
		fflush(stdin);
		gets(str);
		int len=strlen(str);
		//printf("%c\n",str[1]);
		qsort(str,len,sizeof(str[0]),cmp);
		printf("case #%d:\n",i);
		printf("%s\n",str);
	}
	return 0;
}