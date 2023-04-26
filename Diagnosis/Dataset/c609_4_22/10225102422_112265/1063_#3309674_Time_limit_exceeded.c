#include<stdio.h>
#include<string.h>
#include<stdlib.h>
unsigned long long f(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else if (n == 3)
		return 4;
	else if (n == 4)
		return 8;
	else return f(n - 1) + f(n - 2) + f(n - 3) + f(n - 4);
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int n;
		scanf("%d", &n);
		printf("case #%d:\n", i);
		printf("%llu\n", f(n));
	}
}