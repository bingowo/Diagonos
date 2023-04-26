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
	int num = 1;
	int max = 0;
	if(n=1) max = 1;
	while(n>1)
	{
		if( (n&d == ((n>>1)&d)) || (((n&d)!=1) && ((n>>1)&d)!=1) ) num = 1;
		else num++;
		if(num>max) max = num;
		n=n>>1;
	}
	return max;
}