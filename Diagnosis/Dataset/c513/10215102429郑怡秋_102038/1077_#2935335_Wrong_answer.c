#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
typedef struct{
	int A[101];
	int n;
	int m;
	int x; 
	int a;
}qwq;
int cmp(const void*a,const void*b)
{
	qwq*p1=(qwq*)a;qwq*p2=(qwq*)b;
	int i=0,j=0;
	while(i<p1->m) 
	{
		if(p1->x==p1->A[i])
		{
			p1->a=1;
			break;
		}
		i++;
	}
	while(j<p2->m) 
	{
		if(p2->x==p2->A[j])
		{
			p2->a=1;break; 
		}
		j++;
	}
	if(i!=p1->m&&j==p2->m) return -1;
	if(i==p1->m&&j!=p2->m) return 1;
	if(i!=p1->m&&j!=p2->m) return i-j;
	else return j-i;
}
int cmp1(const void*a,const void*b)
{
	int *p1=(int*)a;int*p2=(int*)b;
	return *p1-*p2;
}

int main()
{
	int m,n;
	scanf("%d",&m);
	int B[501];
	for(int i=0;i<m;i++) scanf("%d",&B[i]);
	scanf("%d",&n);
	qwq *p=(qwq*)malloc(n*sizeof(qwq));
	for(int i=0;i<n;i++)
	{
		p[i].a=0;
		p[i].m=m;p[i].n=n;
		for(int j=0;j<m;j++) p[i].A[j]=B[j];
		scanf("%d",&p[i].x); 
	}
	qsort(p,n,sizeof(p[0]),cmp);
	int l=0;int C[502];
	while(p[l].a==1) l++;
	for(int j=l;j<n;j++) C[j-l]=p[j].x;
	qsort(C,n-l,sizeof(C[0]),cmp1);
	for(int i=0;i<l;i++) printf("%d ",p[i].x);
	for(int i=0;i<n-l;i++) printf("%d ",C[i]);
	return 0;
}