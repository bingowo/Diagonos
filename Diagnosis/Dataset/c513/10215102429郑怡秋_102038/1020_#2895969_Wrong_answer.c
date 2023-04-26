#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
typedef struct{
	char time[13];
	int size;
	char name[65];
}qwq;

int cmp_name(const void*a,const void*b)
{
	qwq*p1=(qwq*)a;qwq*p2=(qwq*)b;
	return strcmp(p1->name,p2->name);
}
int cmp_size(const void*a,const void*b)
{
	qwq*p1=(qwq*)a;qwq*p2=(qwq*)b;
	if(p1->size>p2->size) return  1;
	else return -1;
}
int cmp_time(const void*a,const void*b)
{
	qwq*p1=(qwq*)a;qwq*p2=(qwq*)b;
	return strcmp(p1->time,p2->time);
}


int main()
{
	int n;int k=0;
	while(scanf("%d",&n)!=0&&n!=0)
	{
		qwq *A=(qwq*)malloc(n*sizeof(qwq));
		for(int ii=0;ii<n;ii++)
		{
			char a1[10],a2[5];
			scanf("%s%s",a1,a2);
			int j=0;
			for(int i=0;i<10;i++) if(isdigit(a1[i])) A[ii].time[j++]=a1[i];
			for(int i=0;i<5;i++) if(isdigit(a2[i])) A[ii].time[j++]=a2[i];
			scanf("%d",&A[ii].size);
			scanf("%s",A[ii].name);
		}
		char s[5],let[11];
		scanf("%s%s",s,let);
		if(let[1]=='N') qsort(A,n,sizeof(A[0]),cmp_name);
		else if(let[1]=='S') qsort(A,n,sizeof(A[0]),cmp_size);
		else if(let[1]=='T') qsort(A,n,sizeof(A[0]),cmp_time);
		for(int i=0;i<n;i++) 
		{
			for(int h=0;h<12;h++)
			{
				printf("%d",A[i].time[h]-'0');
				if(h==2) printf("-");
				else if(h==4) printf("-");
				else if(h==6) printf(" ");
				else if(h==8) printf(":");
			}
			printf("%17d ",A[i].size);
			printf("%s\n",A[i].name);
		}
	}
	return 0;
}