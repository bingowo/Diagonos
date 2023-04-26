#include <stdio.h>
#include<stdlib.h>
int T,a[1000],R,N;
long long ans[100001];
int cmp(const void *e1,const void *e2)
{
	long long k1=*(long long*)e1,k2=*(long long*)e2;
	long long a=k1,b=k2,cnta=0,cntb=0,counta=0,countb=0;
	if(a<0)
	{
		cnta++;
		a=abs(a);
		a--;
		do
		{
			counta++;
			long long t=a%2;
			a/=2;
			if(!t)
				cnta++;
			cnta=64-counta+cnta;
		}while(a);
	}
	if(a>=0)
	{
		do
		{
			long long t=a%2;
			a/=2;
			if(t)
				cnta++;
		}while(a);
	}
	if(b<0)
	{
		cntb++;
		b=abs(b);
		b--;
		do
		{
			countb++;
			long long t=b%2;
			b/=2;
			if(!t)
				cntb++;
			cntb=64-countb+cntb;
		}while(b);
	}
	if(b>=0)
	{
		do
		{
			long long t=b%2;
			b/=2;
			if(t)
				cntb++;
		}while(b);
	}
	if(cnta!=cntb)
	{
		if(cnta>cntb)
			return -1;
		else
			return 1;
	}
	else
	{
		if(k1>k2)
			return 1;
		else
			return -1;
	}
}
int main()
{
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%d",&N);
		for(int j=0;j<N;j++)
			scanf("%lld",&ans[j]);
		qsort(ans,N,sizeof(ans[0]),cmp);
		printf("case #%d:\n",i);
		for(int j=0;j<N;j++)
			printf("%lld ",ans[j]);
		printf("\n");
	}
	return 0;
}