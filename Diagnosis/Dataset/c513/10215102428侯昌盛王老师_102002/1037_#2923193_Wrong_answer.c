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
	long long int n,m,i;
	scanf("%lld %lld",&n,&m);
	long long int a[n];
	for(i=0;i<n;i++) scanf("%lld",&a[i]);
	qsort(a,n,sizeof(a[0]),cmp);
	long long int sum=0;
	for(i=m-2;i>=0;i--)
	{
		sum=sum+(a[m-1]-a[i]);
	}
	printf("%lld\n",sum);
	return 0;
}