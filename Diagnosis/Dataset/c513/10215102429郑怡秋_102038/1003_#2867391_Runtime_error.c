#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cum(long long int n)
{
	int res=0;
	int i;
	for(i=0;i<64;i++)
	{
		if(n&1==1) res++;
		n>>=1;
	}
	return res;
}


int cmp(const void *p1,const void *p2)
{
	long long int *p3=(long long int*)p1;
	long long int *p4=(long long int*)p2;
	int x,y;
	x=cum(*p3);
	y=cum(*p4);
	if(x>y) return -1;
	else if(x<y) return 1;
	else
	{
		if(*p3>*p4) return 1;
		else return -1;
	}
}


int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int n;
		scanf("%d",&n);
		long long int *p=(long long int*)malloc(T*sizeof(long long int));
		for(int j=0;j<T;j++) scanf("%lld",p+j);
		qsort(p,n,sizeof(long long int),cmp);
		for(int j=0;j<n;j++)
		{
			printf("case #%d:\n%lld\n",j,*p++);
		}
		free(p);
	}
	return 0;
 } 