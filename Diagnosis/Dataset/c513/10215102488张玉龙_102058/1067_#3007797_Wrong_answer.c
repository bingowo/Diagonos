#include<stdio.h>
long long num[51]={0};
int f(int n)
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
		for(int i=1;i<n;i++)
			num[n]+=f(i);
	return num[n];
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%lld",f(n));
	return 0;
}