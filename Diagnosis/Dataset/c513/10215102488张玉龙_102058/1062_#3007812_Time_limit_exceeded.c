#include<stdio.h>
long long num[51]={0};
long long f(int n)
{
	if(n==1)
		num[n]=1;
	else if(n==2)
		num[n]=2;
	else if(n==3)
		num[n]=4;
	else if(n==4)
		num[n]=8;
	else
		num[n]=f(n-1)+f(n-2)+f(n-3)+f(n-4);
	return num[n];
}
int main()
{
	int t,n;
	scanf("%d",&t);
	for(int j=0;j<t;j++)
	{
		scanf("%d",&n);
		printf("%lld",f(n));
	}
	return 0;
}