#include<stdio.h>
#include<math.h>
#include<string.h>

int cmp1(const void *a,const void *b)
{
	long long int* A=(long long int*)a;
	long long int* B=(long long int*)b;
	if((*A>0&&*B>0)||(*A<0&&*B<0)) return(*B-*A);
	else
	{
		if(*A>0&&*B<0) return -1;
		else return 1;
	}
	
}
int cmp2(const void *a,const void *b)
{
	long long int* A=(long long int*)a;
	long long int* B=(long long int*)b;
	if((*A>=0&&*B>=0)||(*A<=0&&*B<=0)) return(*A-*B);
	else
	{
		if(*A>=0&&*B<=0) return 1;
		else return -1;
	}
	
}
int main()
{
	int t,n;
	long long int a[1000],b[1000],sum[10]={0};
	long long int *p1=a,*p2=b;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		for(int j=0;j<n;j++)
		{
			scanf("%lld",&a[j]);
		}
		for(int j=0;j<n;j++)
		{
			scanf("%lld",&b[j]);
		}
		qsort(p1,n,sizeof(long long int),cmp1);
		qsort(p2,n,sizeof(long long int),cmp2);
		for(int j=0;j<n;j++)
		{
			sum[i]=sum[i]+a[j]*b[j];
		}
	}
	

	
	for(int i=0;i<t;i++)
	{
		printf("case #%d:\n%lld\n",i,sum[i]);
	}
	
	
	
	

	
	return 0;
	
	
 } 