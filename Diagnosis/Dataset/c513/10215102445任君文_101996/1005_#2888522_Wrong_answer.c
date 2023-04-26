#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
double p(double x, int y)
{
	int pi;
	double res = 1;
	for (pi = 0; pi < y; pi++)
	{
		res = res * x;
	}
	return res;
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
		n[i] = m-1;
	}
	for (i = 0; i < T; i++)
	{
		printf("case #%d:\n", i);
		printf("%.*lf\n",n[i]*3,res[i]);
	}


	return 0;
}