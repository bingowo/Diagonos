#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*a,const void* b)
{
	long long x=*(long long*)a,y=*(long long*)b;
	int cx=0,cy=0;
	for(int i=0;i<64;i++)	
	{
			if((x>>i)&1)cx++;
			if((y>>i)&1)cy++;
	}
	if(cx>cy)return -1;
	else if(cx<cy)return 1;
	else return (x>y?1:-1);
}
int main()
{
	long long t;
	scanf("%d",&t);
	for(int m=0;m<t;m++)
	{
		long long n;
		scanf("%lld",&n);
		long long num[n];
		for(int i=0;i<n;i++)
			scanf("%lld",&num[i]);
		qsort(num,n,sizeof(long long),cmp);
		printf("case #%d:\n",m);
		for(int i=0;i<n;i++)
			printf("%lld ",num[i]);
	}
	return 0;
}