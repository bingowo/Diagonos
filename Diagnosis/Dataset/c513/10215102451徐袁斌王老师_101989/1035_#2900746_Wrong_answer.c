#include<stdio.h>
#include<math.h>
#include<string.h>

int cmp(const void *a,const void *b)
{
	long long int* A=(long long int*)a;
	long long int* B=(long long int*)b;
	if(*A<*B) return -1;
	else return 1;
}
int main()
{
	long long int n,m,a,b,sum[1000]={0},x=0,r=0;
	long long int *p=sum;
	scanf("%lld %lld",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%lld %lld",&a,&b);
		sum[i]=2*a*b;
		if(a>r) r=a;
	}
	qsort(p,n,sizeof(long long int),cmp);
	for(int j=0;j<m;j++)
	{
		x=x+sum[j];
	}
	x=x+r*r;
	printf("%lld",x);
	

	
	
	
	

	
	return 0;
	
	
 } 