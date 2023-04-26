#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int cmp(const void *a,const void *b)
{
	long long int * A=(long long int *)a;
	long long int * B=(long long int *)b;
	if(*A>=*B) return 1;
	else return -1;
}
int main()
{
	long long int t,j,n,m,a[1000000],sum=0,ans=0;
	scanf("%lld %lld",&n,&m);
	for(t=0;t<n;t++)
	{
		scanf("%lld",&a[t]);
	}
	long long int *p=a;
	qsort(p,n,sizeof(long long int),cmp);
	for(j=m;j<n;j++)
	{
		for(int k=j-m;k<j;k++)
		{
			sum=sum+(a[j+m-1]-a[k]);
		}
		if(sum>ans) ans=sum;
		sum=0;
	}
	printf("%lld",ans);
	

	
	return 0;
	
	
 } 