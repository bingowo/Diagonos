#include<stdio.h>
long long f(int n)
{
	if(n==1)
	{
		return 1;
	}
	return f(n-1)+f(n-2)+f(n-3)+f(n-4);
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