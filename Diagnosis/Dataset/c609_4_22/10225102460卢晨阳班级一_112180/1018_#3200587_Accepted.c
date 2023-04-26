#include<stdio.h>
#include<stdlib.h>

int cmp(const void*a,const void*b){
	return *(int *)a-*(int *)b;
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[100000]={0};
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	qsort(a,n,sizeof(a[0]),cmp);
	long long sum=0;
	for(int i=0;i<n-1;i=i+2)
	sum=sum+a[i+1]-a[i];
	printf("%lld\n",sum);
	return 0;
 } 