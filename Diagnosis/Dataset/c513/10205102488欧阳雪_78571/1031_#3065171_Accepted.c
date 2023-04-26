#include<stdio.h>
#include<stdlib.h>
#define M 1001
int cmp1(const void*a,const void*b)
{
	int c=*(int*)a;
	int d=*(int*)b;
	return c-d; 
}
int cmp2(const void*a,const void*b)
{
	int c=*(int*)a;
	int d=*(int*)b;
	return d-c; 
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int n;
		scanf("%d",&n);
		int a[M]={0};
		int b[M]={0};
		int j=0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
		}
		for(j=0;j<n;j++)
		{
			scanf("%d",&b[j]);
		}
		qsort(a,n,sizeof(a[0]),cmp1);
		qsort(b,n,sizeof(b[0]),cmp2);
		long long int ans=0;
		for(j=0;j<n;j++)
		{
			ans+=a[j]*b[j];
		}
		printf("case #%d:\n",i);
		printf("%lld\n",ans);
	}
}