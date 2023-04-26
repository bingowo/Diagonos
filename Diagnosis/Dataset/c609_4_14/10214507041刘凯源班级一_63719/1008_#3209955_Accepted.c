#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sov(char s[], const int len)
{
	int p = 1;
	int is_int = 1;
	for(p; p <= len; ++p)
	{
		if(s[p] == '.')
		{
			is_int = 0;
			break;
		}
	}
	if(is_int)
	{
		int x = 0;
		int pot = 1;
		int neg = 0;
		if(s[pot] == '-')
		{
			neg = 1;
			++pot;
		}
		for(pot; pot <= len; ++pot)
		{
			x = x * 10 + s[pot] - '0';
		}
		if(neg)
		{
			x = -x;
		}
		unsigned int*p = &x;
		unsigned int mod = (1u << 8 ) - 1;
		for(int i = 0; i < 4; ++i)
		{
			int mv = i * 8;
			int out = (((*p) >> mv ) & mod);
			printf("%02x ", out);
		}
		putchar('\n');
	}
	else
	{
		double x = 0;
//		double y = 0.1;
//		int pot = 1;
//		int neg = 0;
//		if(s[pot] == '-')
//		{
//			neg = 1;
//			++pot;
//		}
//		for(pot; pot <= len; ++pot)
//		{
//			if(s[pot] == '.')
//			{
//				++pot;
//				break;
//			}
//			x = x * 10 + s[pot] - '0';
//		}
//		for(pot; pot <= len; ++pot)
//		{
//			x = x + (s[pot] - '0') * y;
//			y *= 0.1;
//		}
//		if(neg)
//		{
//			x = -x;
//		}
		x = atof(s + 1);
		unsigned long long*p = &x;
		unsigned long long mod = (1ull << 8 ) - 1;
		for(int i = 0; i < 8; ++i)
		{
			int mv = i * 8;
			int out = (((*p) >> mv ) & mod);
			printf("%02x ", out);
		}
		putchar('\n');
	}
}
int main()
{
	char s[50];
	while(scanf("%s", s + 1) != EOF)
	{
		sov(s, strlen(s + 1));
	}
}