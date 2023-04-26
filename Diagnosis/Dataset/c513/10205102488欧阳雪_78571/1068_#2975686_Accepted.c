#include<stdio.h>
long long f(int n,int m)
{
	if(n<m)
	{
		return 0;
	}
	if(n==m)
	{
		return 1;
	}
	return 2*f(n-1,m)-f(n-m-1,m)+(1<<(n-m-1));
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while(n!=-1||m!=-1)
	{
		printf("%lld\n",f(n,m));
		scanf("%d%d",&n,&m);
	}
}