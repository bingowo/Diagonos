#include <stdio.h>
long long f(int n)
{
	long long a[121];
	a[0] = 0;
	a[1] = 1;
	a[2] = 1;
	for (int i = 3; i <= n; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	return a[n];
}

int main()
{
	int t;
	scanf("%d", &t);
	int n;
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		printf("case #%d:\n", i);
		printf("%lld\n", f(n));
	}
	return 0;
}