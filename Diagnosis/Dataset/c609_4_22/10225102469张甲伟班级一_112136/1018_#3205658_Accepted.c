#include <stdio.h>
#include<stdlib.h>
int T,a[100001],book[1000],n;
long long sum;
int cmp(const void *e1,const void *e2)
{
	return *(int*)e1-*(int*)e2;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(a[0]),cmp);
	for(int i=0;i<n;i=i+2)
		sum=sum+a[i+1]-a[i];
	printf("%lld",sum);
	return 0;
}