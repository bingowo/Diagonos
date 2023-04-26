#include<stdio.h>
unsigned long long int a[51];
int main()
{
	int T,n;scanf("%d",&T);
	int i,j,k;
	a[0]=1;
    a[1]=1;
    a[2]=2;
    a[3]=4;
	for(i=0;i<T;i++)
	{
		scanf("%d",&n);
		for(j=4;j<=n;j++)a[j]=a[j-1]+a[j-2]+a[j-3]+a[j-4];
		printf("case #%d:\n%llu\n",i,a[n]);
	}
	return 0;
}