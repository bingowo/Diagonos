#include<stdio.h>
int a[10000000], tot;
void sov()
{
	long long n;
	scanf("%lld", &n);
	tot = 0;
	if(n == 0)
	{
		puts("0");
		return;
	}
	while(n)
	{
		a[++tot] = n % 2333;
		n /= 2333;
	}
	for(int i = tot; i >= 1; --i)
	{
		printf("%lld ", a[i]);
	}
	puts("");
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		sov();
}