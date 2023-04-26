#include<stdio.h>
#include<stdlib.h>
#define max(a, b) (a > b ? a : b)
int num(int n, int i)
{
	return (n >> i) & 1;
}
int nm[40];
int sov()
{
	long long n;
	scanf("%lld", &n);
	if(n == 0)
	{
		printf("%d", 0);
		return 0;
	}
	int ans = 0, sum = 1;
	int tot = 0;
	while(n)
	{
		nm[++tot] = n & 1;
		n >>= 1;
	}
//	for(int i = 1; i <= tot; ++i)
//		printf("%d", nm[i]);
	for(int i = 1; i < tot; ++i)
	{
		if(nm[i] ^ nm[i + 1])
			++sum;
		else
			sum = 1;
		ans = max(ans, sum);
		
	}
	printf("%d\n", ans);
}
int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i)
	{
		printf("case #%d:\n", i);
		sov();
	}
}