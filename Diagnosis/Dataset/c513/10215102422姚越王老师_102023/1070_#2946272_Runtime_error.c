#include<stdio.h> 
typedef unsigned long long ull;

int main()
{
	int n,i;
	while(~scanf("%d",&n))
	{
		if(n==-1)return 0;
		ull a[n+1];
		a[1]=2;a[2]=4;a[3]=7;
		for(i=4;i<=n;++i)a[i]=2*a[i-1]-a[i-2]+a[i-3];
		printf("%llu\n",a[n]);
	}
}