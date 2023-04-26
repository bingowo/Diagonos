#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define N 30
int ipow(int n, int x)
{
	int i; int result = 1;
	for (i = 0; i <x; i++)
		result = result*n;
	return result;
}
int GCD(int num1, int num2)
{
	return num1%num2 ? GCD(num2, num1%num2) : num2;
}
int main()
{
	char s[N];
	fgets(s, N, stdin);
	int i;
	for (i = 0;s[i]!='.'&&s[i]!='\n'; i++);
	int point = i; int num = 0;
	for (i = point - 1; i >= 0; i--)
	{
		if (s[i] == '2')
			num = num + (-1)*ipow(3, point - 1 - i);
		else if (s[i] == '1')
			num = num + ipow(3, point - 1 - i);
	}
	int menber = 0, denominator;
	int len = strlen(s);
	if (s[point] == '.')
	{
		for (i = point + 1; i<len; i++)
		{
			if (s[i] == '2')
				menber = menber + (-1)*ipow(3, len - 1 - i);
			else if (s[i] == '1')
				menber = menber + ipow(3, len - 1 - i);
		}
		denominator = ipow(3, len - 1 - point);
		int gcd;
		if (menber<0&&num>0)
		{
			num = num - 1;
			menber = -menber;
			gcd = GCD(menber, denominator);
			printf("%d %d %d\n", num,( denominator / gcd-menber / gcd), denominator / gcd);
		}
		else if (menber>=0&&num>=0)
		{
			gcd = GCD(menber, denominator);
			printf("%d %d %d\n", num, menber / gcd, denominator / gcd);
		}
		else if (menber >0&& num < 0)
		{
			num = num + 1;
			gcd = GCD(menber, denominator);
			printf("%d %d %d\n", num, (denominator / gcd - menber / gcd), denominator / gcd);
		}
	}
	else 
		printf("%d\n", num);
	return 0;
}