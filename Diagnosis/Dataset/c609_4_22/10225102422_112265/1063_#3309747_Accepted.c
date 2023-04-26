#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 50
unsigned long long s[N+1]={0,1,2,4,8};
unsigned long long f(int n)
{
    for(int i=5;i<=n;i++)
    {
        s[i]=s[i-1]+s[i-2]+s[i-3]+s[i-4];
    }
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else if (n == 3)
		return 4;
	else if (n == 4)
		return 8;
	else
	{
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