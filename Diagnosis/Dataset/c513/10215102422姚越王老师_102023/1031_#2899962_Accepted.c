#include<stdio.h>
#include<stdlib.h>
int cmp1(const void* a,const void* b)
{
	int *p1=(int*)a,*p2=(int*)b;
	return *p1-*p2;
}
int cmp2(const void* a,const void* b)
{
	int *p1=(int*)a,*p2=(int*)b;
	return *p2-*p1;
}
int main()
{
	int T,n,i,j,ans;scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d",&n);
		int a[n],b[n];
		for(j=0;j<n;j++)scanf("%d",&a[j]);
		for(j=0;j<n;j++)scanf("%d",&b[j]);
		qsort(a,n,sizeof(int),cmp1);
		qsort(b,n,sizeof(int),cmp2);
		ans=0;
		for(j=0;j<n;j++)ans+=a[j]*b[j];
		printf("case #%d:\n%d\n",i,ans);
	}
	return 0;
}