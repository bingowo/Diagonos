#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
	int* x=(int*)a;int* y=(int*)b;
	return *x<*y;
}
int  main()
{
	int i,t,j,n,p;
	long long result;
	int a[1000],b[1000];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		result=0;
		scanf("%d",&n);
		for(j=0;j<n;j++)
			scanf("%d",&a[j]);
		for(j=0;j<n;j++)
			scanf("%d",&b[j]);
		qsort(a,n,sizeof(a[0]),cmp);
		qsort(b,n,sizeof(b[0]),cmp);
		for(p=0;p<n;p++)
		{
			result+=a[p]*b[n-p-1];
		}
		printf("case #%d:\n%lld\n",i,result);
	}
 } 