#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
	long long int q,p;
	q=*(long long int*)a;
	p=*(long long int*)b;
	return q-p;
}

int main()
{
	long long int n,m,i,j;
	scanf("%lld %lld",&n,&m);
	long long int a[n];
	for(i=0;i<n;i++) scanf("%lld",&a[i]);
	qsort(a,n,sizeof(a[0]),cmp);
	//printf("%lld %lld\n",a[4],a[5]);
	long long int sum=0,min=1e18;
	for(i=n-1;i>=m-1;i--)
	{
		for(j=i-1;j>i-m;j--)
		{
			sum=sum+(a[i]-a[j]);
		//	printf("%lld\n",sum);
		}
		if(sum<min) min=sum;
		sum=0;
	}
	
	printf("%lld\n",min);
	return 0;
}