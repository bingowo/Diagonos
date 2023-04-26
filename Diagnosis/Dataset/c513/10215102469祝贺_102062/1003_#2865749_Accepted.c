#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void* b)
{
	long long x=*(long long*)a,y=*(long long*)b;
	int cx=0,cy=0;
	for(int i=0;i<64;i++)	
	{
			if((x>>i)&1==1)cx++;
			if((y>>i)&1==1)cy++;
	}
	if(cx>cy)return -1;
	else if(cx<cy)return 1;
	else return (x>y?1:-1);
}
int main()
{
	long long t;
	scanf("%lld",&t);
	for(int m=0;m<t;m++)
	{
		int n;
		scanf("%d",&n);
		long long num[n];
		for(int i=0;i<n;i++)
			scanf("%lld",&num[i]);
		printf("case #%d:\n",m);
		    qsort(num,n,sizeof(num[0]),cmp);
		    int i=0;
		    for(;i<n-1;i++)
			    printf("%lld ",num[i]);
			printf("%lld\n",num[i]);
	}
	return 0;
}