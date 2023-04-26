#include<stdio.h>
int a[100000], tot;
void sov()
{
	long long n;
	scanf("%lld", &n);
	tot = 0;
	while(n)
	{
		a[++tot] = n % 2333;
		n /= 2333;
	}
	for(int i = tot; i >= 1; --i)
	{
		printf("%d ", a[i]);
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