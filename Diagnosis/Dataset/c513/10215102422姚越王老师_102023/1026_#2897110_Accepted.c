#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int cmp(const void* a,const void* b)
{
	int *p1=(int*)a,*p2=(int*)b;
	return *p1-*p2;
}
int main()
{
	int n;scanf("%d",&n);
	int i,a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(a[0]),cmp);
	int sum=0;
	for(i=0;i<n;i++)
	{
		sum+=abs(a[i]-a[i+1]);
		i++;}
	printf("%d",sum);
	return 0;
}