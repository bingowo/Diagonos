#include<stdio.h>
#include<string.h>
#include<math.h>
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
int main()
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
		printf("%d", a);
		return 0;
	}
	else
	{
		if(a == 0)
		{
			int g = gcd(abs(b), abs(c));
			b = b / g;
			c = c / g;
			printf("%d %d", b, c);
			return 0;
		}
		else if((a > 0 && b > 0) || (a < 0 && b < 0))
		{
			int g = gcd(abs(b), abs(c));
			b = b / g;
			c = c / g;
			printf("%d %d %d", a, abs(b), c);
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
				printf("%d %d", b, c);
			}
			else
			{
				printf("%d %d %d", a, b, c);
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
				printf("-%d %d", b, c);
			}
			else
			{
				printf("%d %d %d", a, b, c);
			}
			return 0;
		}
	}
}