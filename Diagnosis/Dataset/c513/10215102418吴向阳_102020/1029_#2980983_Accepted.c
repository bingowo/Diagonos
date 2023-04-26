#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
	if (*(char *)a - *(char *)b > 0) return 1;
	else return -1;
}

int main()
{
	int T,t;
	scanf("%d\n",&T);
	t=T;
	while(T)
	{
		char a[500],b[500];
		gets(a);
		char *p = a;
		int x = 0;
		while(*p)
		{
			if(*p - 'A' >= 0 && *p -'Z' <= 0)
			{
				b[x] = *p;
				p++,x++;
			}
			else p++;
		}
		qsort(b,x,sizeof(b[0]),cmp);
		p = a;
		char *q = b;
		printf("case #%d:\n",t-T);
		while(*p)
		{
			if(*p - 'A' >= 0 && *p -'Z' <= 0)
			{
				printf("%c",*q);
				p++,q++;
			}
			else
			{
				printf("%c",*p);
				p++;
			}
		} 
		printf("\n");
		T--;
	}
	return 0;
}