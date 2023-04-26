#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
	double q,p;
	q=*(double*)a;
	p=*(double*)b;
	if(q>p) return 1;
	else if(q<p) return -1;
	else return 0;
}

int main()
{
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	double a[n];
	for(i=0;i<n;i++) scanf("%lf",&a[i]);
	qsort(a,n,sizeof(a[0]),cmp);
	//printf("%lld %lld\n",a[4],a[5]);
	double sum=0,min=1e18;
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
	
	printf("%.0lf\n",min);
	return 0;
}