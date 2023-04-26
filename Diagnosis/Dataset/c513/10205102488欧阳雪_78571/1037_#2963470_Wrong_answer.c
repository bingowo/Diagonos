#include<stdio.h>
#include<stdlib.h>
#define M 2000000
int cmp(const void*a,const void*b)
{
	long long c=*(long long*)a;
	long long d=*(long long*)b;
	return(c-d);
}
int main()
{
	long n,m;
	scanf("%ld%ld",&n,&m);
	long long a[M]={0};
	for(long i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	qsort(a,n,sizeof(long long),cmp);
	long long ans=0;
	for(long j=0;j<m-1;j++)
	{
		ans+=a[m-1]-a[j];
	}
	long long temp=ans;
 for(long long k=m;k<n;k++){
  temp+=(a[k]-a[k-1])*m;
  temp-=(a[k]-a[k-m]);
  if(ans>temp) ans=temp;
 }
	printf("%lld",ans);
 } 
