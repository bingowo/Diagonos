#include <stdio.h>
#include<stdlib.h>
int T,a[1000],R,N;
long long ans[100001];
int cmp(const void *e1,const void *e2)
{
	long long k1=*(long long*)e1,k2=*(long long*)e2;
	long long a=k1,b=k2,cnta=0,cntb=0,counta=0,countb=0;
	for(int k=0;k<64;k++)
		if(((a>>k)&1)==1)			
			cnta++;
	for(int k=0;k<64;k++)
		if(((b>>k)&1)==1)			
			cntb++;
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