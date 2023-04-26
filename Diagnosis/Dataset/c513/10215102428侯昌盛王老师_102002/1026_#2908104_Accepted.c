#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int cmp(const void*a,const void*b)
{
	int *q,*p;
	q=(int*)a;
	p=(int*)b;
	return *q-*p;
}
int main()
{
	int n,i=0;
	scanf("%d",&n);
	int a[n];
	for(i;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	//printf("%d\n",a[1]);
	qsort(a,n,sizeof(a[0]),cmp);
//	printf("%d\n",a[1]);
	int j=0,sum1=0;
	for(j;j<n;j=j+2)
	{
		sum1=sum1+a[j];
		//printf("%d\n",sum1);
	}

	//printf("%d\n",sum1);
	int k=1,sum2=0;
	for(k;k<n;k=k+2)
	{
		sum2=sum2+a[k];
	}
	int sum;
	sum=abs(sum1-sum2);
	printf("%d\n",sum);
	return 0;
	
}