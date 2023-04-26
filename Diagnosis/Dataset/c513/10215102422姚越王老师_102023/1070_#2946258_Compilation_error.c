#include<stdio.h> 
typedef unsigned long long ull;
ull a[n+1];
int main()
{
	int n,i;
	while(~scanf("%d",&n))
	{
		if(n==-1)return 0;
		a[1]=2;a[2]=4;a[3]=7;
		for(i=4;i<=n;++i)a[i]=2*a[i-1]-a[i-2]+a[i-3];
		printf("%llu",a[n]);
	}
}