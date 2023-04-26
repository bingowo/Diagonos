#include<stdio.h>
#include<stdlib.h> 
int main()
{
	long long int a[55]={0};
	a[0]=1;
	a[1]=1;
	a[2]=2;
	a[3]=4;
	for(int i=4;i<=50;i++)
	a[i]=a[i-1]+a[i-2]+a[i-3]+a[i-4];
	int T,x;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%d",&x);
		printf("case #%d:\n%lld\n",i,a[x]);
		
		
		
	}
	return 0;
} 