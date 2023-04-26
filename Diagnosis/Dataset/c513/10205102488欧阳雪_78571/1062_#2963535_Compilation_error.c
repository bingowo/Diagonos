#include<stdio.h>
long long f(int n)
{
	if(n==0)
	{
		return 1;
	}
	if(n==1)
	{
		return 1;
	}
	if(n==2)
	{
		return 2;
	}
	if(n==3)
	{
		return 4;
	}
	f(n)=f(n-1)+f(n-2)+f(n-3)+f(n-4);
	return f(n);
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int n;
		scanf("%d",&n);
		printf("case #%d:\n",i);
		printf("%lld",f(n));
		printf("\n");
	}
}