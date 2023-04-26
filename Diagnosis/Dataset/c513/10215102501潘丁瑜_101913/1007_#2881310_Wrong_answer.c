#include<stdio.h>
int calculate(int n);
int main()
{
	int T,i,n;
	long long int result;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d",&n);
		result = calculate(n);
		printf("case #%d:\n",i);
		printf("%lld\n",result);
	}
	return 0;
}
int calculate(int n)
{
	int d = 1;
	int num = 0;
	while(n>0)
	{
		if(n&d == ((n>>1)&d));
		else num++;
		n=n>>1;
	}
	return num;
}