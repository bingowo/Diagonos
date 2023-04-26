#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
int cmp(const void*a,const void*b)
{
	long long*p1=(long long*)a;long long*p2=(long long*)b;
	if(*p1>*p2) return 1;
	else return -1; 
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	long long *p=(long long*)malloc(n*sizeof(long long));
	for(int i=0;i<n;i++) scanf("%lld",&p[i]);
	qsort(p,n,sizeof(p[0]),cmp);
	long long res=0,ans=0;
	long long sum=0;
	for(int i=0;i<m-1;i++)
	{
		sum+=p[i];
	}res=(m-1)*p[m-1]-sum;
	for(int i=1;i<=n-m;i++)
	{
		sum+=p[m+i-2]-p[i-1];
		ans=(m-1)*p[m+i-1]-sum;
		if(ans<res) res=ans;
	}
	printf("%lld",res);
	return 0;
}