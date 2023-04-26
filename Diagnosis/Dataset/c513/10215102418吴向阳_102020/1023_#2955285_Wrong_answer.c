#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
{
	char *p1=(char *)a,*p2=(char *)b;
	int x=0,y=0;
	while(*p1)
	{
		if((*p1-'0')>-1 && (*p1-'0')<10)
		{
			while((*p1-'0')>-1 && (*p1-'0')<10)
			{
				x=x*10+(*p1-'0');
				*p1++;
			}
			p1=(char *)a;
			break;
		}
		*p1++;
	}
	while(*p2)
	{
		if((*p2-'0')>-1 && (*p2-'0')<10)
		{
			while((*p2-'0')>-1 && (*p2-'0')<10)
			{
				y=y*10+(*p2-'0');
				*p2++;
			}
			p2=(char *)b;
			break;
		}
		*p2++;
	}
	if (x!=0 && y!=0) return x-y; 
	else if((x==0 && y==0)||(x ==y))
	{
		while (*p1 && *p2)
		{
			if(*p1 >*p2) return 1;
			else if (*p1<*p2) return -1;
			else 
			{
				*p1++;
				*p2++;
			}
			if(*p1) return 1;
			else if (*p2) return -1;
			else return 0;
		}
	}
	else return x-y;
}

int main()
{
	char a[110][40];
	int i=0;
	while(scanf("%s",a[i++])!=EOF);
	qsort(a[0],i,sizeof(a[0]),cmp);
	for (int j=0;j<i;j++) printf("%s ",a[j]);
	return 0;
} 