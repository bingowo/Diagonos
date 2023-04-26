#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cum(long long int n)
{
	int res=0;
	int i;
	for(i=0;i<64;i++)
	{
		if(n&1==1) res+=1;
		n>>=1;
	}
	return res;
}
int cmp(const void*a,const void *b)
{
	long long *p1=(long long *)a;
	long long *p2=(long long *)b;
	int x=cum(*p1),y=cum(*p2);
	if(x>y ) return -1;
	else if(x<y) return 1;
	else
	{
		if(*p1>*p2) return 1;
		else return -1;
	}
	
}
int main()
{
	int  T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int n;
		scanf("%d",&n);
		long long *a=(long long *)malloc(n*sizeof(long long));
		for(int j=0;j<n;j++) scanf("%lld",&a[j]);
		qsort(a,n,sizeof(a[0]),cmp);
		printf("case #%d:\n",i);
		for(int j=0;j<n-1;j++) printf("%lld ",a[j]);
		printf("%lld\n",a[n-1]);
		free(a);
	}
	return 0;
}