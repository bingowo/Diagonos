#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
typedef struct{
	int day;
	char B[10];
	int year;
}qwq;
const char A[20][10]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
int cmp(const void*a,const void*b)
{
	qwq* p1=(qwq*)a;qwq* p2=(qwq*)b;
	if(p1->year<p2->year) return -1;
	else if(p1->year>p2->year) return 1;
	else
	{
		int x1=0,x2=0;
		while(strcmp(p1->B,A[x1])!=0) x1++;
		while(strcmp(p2->B,A[x2])!=0) x2++;
		if(x1<x2) return -1;
		else if(x1>x2) return 1;
		else return p1->day-p2->day;
	}
 } 
 

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int t=0;
		scanf("%d",&t);
		qwq *h=(qwq*)malloc(t*sizeof(qwq));
		for(int j=0;j<t;j++)
		{
			scanf("%d. %s %d",&h[j].day,h[j].B,&h[j].year);
		}
		qsort(h,t,sizeof(h[0]),cmp);
		printf("case #%d:\n",i);
		for(int j=0;j<t;j++) 
		{
			printf("%d. %s %d\n",h[j].day,h[j].B,h[j].year);
		}
		free(h);
	}
	return 0;
}