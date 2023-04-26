#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	scanf("%d",&n);
	int *a=(int *)malloc(sizeof(int)*n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);	
	}
	long long int sum=0;
	for(int i=0;i<n/2;i++)
	sum+=a[2*i+1]-a[2*i];
	printf("%lld",sum);
	
free(a);
	return 0;
} 