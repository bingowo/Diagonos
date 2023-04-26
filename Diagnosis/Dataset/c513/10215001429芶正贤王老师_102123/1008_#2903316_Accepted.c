#include<stdio.h>
void func(int a,int b);

int main()
{
	int T;//T组测试数据
	scanf("%d",&T);
	int index;
	long long int a[T],b[T];
	for(index = 0;index < T;index++)
	{
		scanf("%lld %lld",&a[index],&b[index]);
		func(a[index],b[index]);
	 } 
	 return 0;
}

void func(int a,int b)
{
	long long int digit;
	digit = (a^b);

	int j = 0,ans = 0;
	for( ; digit / 2 != 0;j++)
	{
		if(digit % 2 == 1) ans++;
		digit = digit / 2;
	}
	ans++;
	printf("%lld\n",ans);
}