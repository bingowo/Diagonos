#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h> 
int cmp(const void*a,const void*b)
{
	long long*p1=(long long*)a;
	long long*p2=(long long*)b;
	long long x=*p1;long long y=*p2;
	x=(x>0)?x:(-1)*x;
	y=(y>0)?y:(-1)*y;
	while(x>=10) x/=10;
	while(y>=10) y/=10;
	if(x>y) return -1;
	else if(x<y) return 1;
	else
	{
		if(*p1>*p2) return 1;
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
		long long A[10010];
		for(int j=0;j<n;j++) scanf("%lld",&A[j]);
		qsort(A,n,sizeof(A[0]),cmp);
		printf("case #%d:\n",i);
		for(int j=0;j<n-1;j++) printf("%lld ",A[j]);
		printf("%lld\n",A[n-1]);
	}
	return 0;
}