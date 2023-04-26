#include<stdio.h>
#include<stdlib.h>
#define M 100000
int cmp(const void*a,const void*b)
{
	long long c=*(long long*)a;
	long long d=*(long long*)b;
	return(c-d);
}
int main()
{
	long long n,m;
	scanf("%lld%lld",&n,&m);
	long long a[M]={0};
	for(long long i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	qsort(a,n,sizeof(a[0]),cmp);
	long long ans=0;
	for(long long j=0;j<m-1;j++)
	{
		ans+=a[m-1]-a[j];
	}
	printf("%lld",ans);
 } 