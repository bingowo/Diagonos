#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
long long pow(int x)
{
	long long res=1;
	for(int i=0;i<x;i++)
	{
		res*=2;
	}
	return res;
}

typedef struct{
	long long x;long long y;
	long long mah;
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
	printf("%lld\n",llabs(p[0].x-p[1].x)+llabs(p[0].y-p[1].y));
	int sum=0;
	for(int i=0;i<n-1;i++)
	{
		long long ans=llabs(p[i].x-p[i+1].x)+llabs(p[i].y-p[i+1].y);
		if(ans%2==0) break;
		else 
		{
			for(int j=0;j<64;j++)
			{
				long long q=pow(j);//printf("%lld\n",q);
				if(ans>q/2&&ans<q)
				{
					sum+=j;
					break;
				}
			}
		}
	}
	printf("%d\n",sum);
	return 0;
}