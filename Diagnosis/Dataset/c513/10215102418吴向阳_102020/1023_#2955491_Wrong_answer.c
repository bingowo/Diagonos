#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void READ(char a[][40],char b[],int i)
{
	int k=0,length=strlen(b),j=0;
	while(j<length)
	{
		while (b[j]!=' ')
		{
			a[i][k]=b[j];
			k++,j++;
		}
		if (b[j]==' ') j++;
		a[i][k]='\0';
		k=0;
		i++;
	}
}


int strnumcmp(const void *a,const void *b)
{
	char *p1=(char *)a,*p2=(char *)b;
	unsigned x=-1,y=-1;
	while(*p1)
	{
		if((*p1-'0')>-1 && (*p1-'0')<10)
		{
			x=0;
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
			y=0;
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
	if(x == y)
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
		}
		if(*p1) return 1;
		else if (*p2) return -1;
		else return 0;
	}
	else if (x!=-1 && y!=-1)
	{
		if(x-y>0) return 1;
		else if (x-y<0) return -1;
		else return 0;
	}
}


int main()
{
	char a[110][40],b[4400];
	int i=0;
	gets(b);
	READ(a,b,i);
	printf("%d\n",i);
	for (int k=0;k<i;k++) printf("%s ",a[k]);
	qsort(a[0],i,sizeof(a[0]),strnumcmp);
	for (int j=0;j<i;j++) printf("%s ",a[j]);
	return 0;
} 