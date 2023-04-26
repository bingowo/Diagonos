#include<stdio.h>
#include<limits.h>
#define int long long
#define abs(x) (x >= 0 ? x : -x)
void poow(int *a, int *b, int c, int d, int r)
{
	int aa = *a;
	int bb = *b;
	*a = (aa * c - bb * d) + r;
	*b = (aa * d + bb * c);
	return;
}
int getnum(char c)
{
	if('0' <= c && c <= '9')
		return c - '0';
	else
		return c - 'A' + 10;
}
char s[100];

signed main()
{
	scanf("%s", s + 1);
	int a = 0, b = 0;
	for(int i = 3; i <= strlen(s + 1); ++i)
	{
		int x = getnum(s[i]);
		for(int j = 3; j >= 0; --j)
		poow(&a, &b, -1, 1, (x >> j) & 1);
	}
	
//	printf("%d %d\n", a, b);
	if(a && b)
	{
		if(b > 0)
		{
			if(b == 1)
				printf("%lld+i", a);
			else
				printf("%lld+%lldi", a, b);
		}
		else
		{
			if(b == -1)
				printf("%lld-i", a);
			else
				printf("%lld%lldi", a, b);
		}
	}
	else if(a)
	{
		printf("%lld", a);
	}
	else if(b)
	{
		if(b == 1)
			puts("i");
		else if(b == -1)
			puts("-i");
		else
			printf("%lldi", b);
		
	}
	else
	{
		puts("0");
	}
	return 0;
}