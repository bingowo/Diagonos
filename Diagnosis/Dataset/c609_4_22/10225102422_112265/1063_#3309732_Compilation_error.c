#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 50
unsigned long long s[N+1];
unsigned long long f(int n)
{
	if (n == 1)
		return 1;
	s[1]=1;
	else if (n == 2)
		return 2;
	s[2]=2;
	else if (n == 3)
		return 4;
	s[3]=4;
	else if (n == 4)
		return 8;
	s[4]=8;
	else
	{
	    s[n]=s[n-1]+s[n-2]+s[n-3]+s[n-4];
	    return s[n];
	}
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