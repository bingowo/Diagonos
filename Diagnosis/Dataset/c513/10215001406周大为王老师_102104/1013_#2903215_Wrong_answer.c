#include<stdio.h>
#include<string.h>
#include<math.h>
int gcd(long long b, long long c)
{
	long long max = 1;
	for (int i = 2;i < b;i += 3)
	{
		if (b%i == 0 && c%i == 0)
		{
			max = i;
		}
	}
	return max;
}
int main()
{
	unsigned int p = 0;
	long long b = 0, c = 1, a = 0;
	char ch[31] = { 0 };
	gets(ch);
	for (;p < strlen(ch);p++)
	{
		if (ch[p] == '.')
			break;
		a = a * 3;
		if (ch[p] == '1')
			a++;
		if (ch[p] == '2')
			a--;
	}//整数
	p++;
	for (;p < strlen(ch);p++)
	{
		b = b * 3;
		c = c * 3;
		if (ch[p] == '1')
			b++;
		if (ch[p] == '2')
			b--;
	}
	if (a > 0 && b < 0)
	{
		a--;
		b += c;
	}
	if (a == 0)
	{
		b = -b;
	}
	if (a<0 && b>0)
	{
		a++;
		b = c-b;
	}
	long long ret = gcd(abs(b),abs(c));
	if (b == 0)
	{
		printf("%lld\n", a);
	}
	else
	{
		if (a != 0) printf("%lld ", a);
		printf("%lld %lld\n", b / ret, c / ret);
	}
	return 0;
}