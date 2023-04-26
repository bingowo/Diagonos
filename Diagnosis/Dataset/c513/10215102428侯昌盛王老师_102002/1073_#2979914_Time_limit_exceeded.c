#include <stdio.h>
int h(long long int i)
{
	long long int k;
	while(i)
	{
		k=i%10;
		if(k==9) return -1;
		else i/=10;
	}
	return 1;
}

int main()
{
	long long int a,b;
	scanf("%lld %lld",&a,&b);
	long long int i;
	int n=0;
	for(i=a;i<=b;i++)
	{
		if(i%9!=0&&h(i)==1) n++;
	}
	printf("%d\n",n);
	return 0;
}