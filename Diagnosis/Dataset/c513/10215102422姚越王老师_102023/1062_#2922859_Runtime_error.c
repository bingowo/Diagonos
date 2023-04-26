#include<stdio.h>
int main()
{
	int T,n;scanf("%d",&T);
	int i,j,k;
	for(i=0;i<T;i++)
	{
		scanf("%d",&n);
		long long int a[n+1];
		a[0]=1;
		a[1]=1;
		a[2]=2;
		a[3]=4;
		for(j=4;j<=n;j++)a[j]=a[j-1]+a[j-2]+a[j-3]+a[j-4];
		printf("case #%d:\n%lld\n",i,a[n]);
	}
	return 0;
}