#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h> 

int cmp(const void *a,const void *b)
{
	int* p1=(int*)a;
	int* p2=(int*)b;
	while(*p1!=-1&&*p2!=-1&&*p1==*p2) p1++,p2++;
	return *p2-*p1;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int n;
		scanf("%d",&n);
		int date[1000][51];
		for(int k=0;k<n;k++)
		{
			int j=0;
			while(scanf("%d",date[k][j])&&date[k][j]!=-1) j++;
		}
		qsort(date,n,sizeof(date[0]),cmp);
		for(int k=0;k<n;k++)
		{
			int j;
			for(j=0;date[k][j+1]!=-1;j++) printf("%d ",date[k][j]);
			printf("%d\n",date[k][j]);
		}
	 } 
	return 0;
}