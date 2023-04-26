#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
unsigned long long po(int x)
{
	unsigned long long res=1;
	for(int i=0;i<x;i++)
	{
		res*=2;
	}
	return res;
}

typedef struct{
	long long x;long long y;
	unsigned long long mah;
}qwq;

int cmp(const void*a,const void*b)
{
	qwq*p1=(qwq*)a;qwq*p2=(qwq*)b;
	if(p1->mah>p2->mah) return -1;
	else if(p1->mah<p2->mah) return 1;
	else
	{
		if(p1->x>p2->x) return 1;
		else if(p1->x<p2->x) return -1;
		else 
		{
			if(p1->y>p2->y) return 1;
			else return 1;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	qwq *p=(qwq*)malloc(n*sizeof(qwq));
	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld",&p[i].x,&p[i].y);
	}
	for(int i=0;i<n;i++) p[i].mah=llabs(p[i].x)+llabs(p[i].y);
	qsort(p,n,sizeof(p[0]),cmp);
	unsigned long long ab,ac;
	if(p[0].x<p[1].x) ab=p[1].x-p[0].x;
	else ab=p[0].x-p[1].x;
	if(p[0].y<p[1].y) ac=p[1].y-p[0].y;
	else ac=p[0].y-p[1].y
	unsigned long long qq=ab+ac;
	printf("%llu\n",llabs(p[0].x-p[1].x)+llabs(p[0].y-p[1].y));
	int sum=0;
	for(int i=0;i<n-1;i++)
	{
		unsigned long long ans=llabs(p[i].x-p[i+1].x)+llabs(p[i].y-p[i+1].y);
		if(ans%2==0&&ans>0) break;
		else 
		{
			if(ans>po(63)) 
			{
				sum+=64;
				continue;
			}
			for(int j=0;j<64;j++)
			{
				unsigned long long q=po(j);
				if(ans>=q/2&&ans<q)
				{
					//printf("\n%d %d\n",i,j);
					sum+=j;
					break;
				}
			}
		}
	}
	printf("%d\n",sum);
	return 0;
}