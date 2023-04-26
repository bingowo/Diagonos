#include<stdio.h>
#include<string.h>
#include<math.h>
#define int long long
int gcd(int a, int b)
{
	if(a == 0 || b == 0)
		return 0;
	while(b ^= a ^= b ^= a %= b);
	return a;
}
int getnum(char c)
{
	int x = c - '0';
	return x == 2 ? -1 : x;
}
signed main()
{
	char s[35];
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	int p = 1;
	int a = 0, b = 0, c = 1;
	for(p; p <= len; ++p)
	{
		if(s[p] == '.')
		{
			++p;
			break;
		}
		a = a * 3 + getnum(s[p]);
	}
	for(p; p <= len; ++p)
	{
		c = c * 3;
		b = b * 3 + getnum(s[p]);
	}
//	printf("%d %d %d", a, b, c);
	if(b == 0)
	{
		printf("%lld", a);
		return 0;
	}
	else
	{
		if(a == 0)
		{
			int g = gcd(abs(b), abs(c));
			b = b / g;
			c = c / g;
			printf("%lld %lld", b, c);
			return 0;
		}
		else if((a > 0 && b > 0) || (a < 0 && b < 0))
		{
			int g = gcd(abs(b), abs(c));
			b = b / g;
			c = c / g;
			printf("%lld %lld %lld", a, abs(b), c);
			return 0;
		}
		else if(a > 0 && b < 0)
		{
			--a;
			b = c + b;
			int g = gcd(abs(b), abs(c));
			b = b / g;
			c = c / g;
			if(a == 0)
			{
				printf("%lld %lld", b, c);
			}
			else
			{
				printf("%lld %lld %lld", a, b, c);
			}
			return 0;
		}
		else if(a < 0 && b > 0)
		{
			++a;
			b = c - b;
			int g = gcd(abs(b), abs(c));
			b = b / g;
			c = c / g;
			if(a == 0)
			{
				printf("-%lld %lld", b, c);
			}
			else
			{
				printf("%lld %lld %lld", a, b, c);
			}
			return 0;
		}
	}
}