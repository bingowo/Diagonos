#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
double p(double x, int y)
{
	int i;
	double res = 1;
	for (i = 0; i < y; i++)
	{
		res = res * x;
	}
	return res;
}
int dian(const double number)
{
	double n = number;
	for (int i = 0; i < 50; i++)
	{
		n = n * 10;
		if (n - (int)n == 0)
		{
			return i + 1;
			break;
		}
	}
}
int main()
{
	int T, i, m, temp, n[10] = { 0 };
	double res[10] = { 0 };
	char c;
	scanf("%d", &T);
	c = getchar();
	for (i = 0; i < T; i++)
	{
		c = getchar();
		c = getchar();
		m = 1;
		while ((c = getchar()) != '\n')
		{
			temp = c - '0';
			res[i] = res[i] + temp * p(0.125, m);
			m++;
		}
	}
	for (i = 0; i < T; i++)
	{
		n[i] = dian(res[i]);
	}
	for(i=0;i<T;i++)
	{
		printf("case #%d:\n", i);
		printf("%.*lf\n",n[i], res[i]);
	}
	return 0;
}