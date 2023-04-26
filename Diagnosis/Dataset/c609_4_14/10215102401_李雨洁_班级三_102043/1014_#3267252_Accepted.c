#include <stdio.h>
#include <string.h>
int main()
{
	int A, B, a;
	scanf("%d %d", &A, &B);
	int b[100] = { 0 }, c[100] = { 0 };
	if (A / B)
	{
		a = A / B;
		A = A - a * B;
	}
	else a = 0;
	int m = 1, n = 1;
	while (a / 3 != 0 || a % 3 != 0)
	{
		b[m] = a % 3;
		a /= 3;
		m++;
	}
	while (A)
	{
		B /= 3;
		if (A >= B)
		{
			c[n] = A / B;
			A = A - c[n] * B;
		}
		else c[n] = 0;
		n++;
	}
	for (int i = n - 1; i >= 1; i--)
	{
		c[i]++;
		if (c[i] >= 3 && i != 1)
		{
			c[i] -= 3;
			c[i - 1]++;
		}
		if (c[i] >= 3 && i == 1)
		{
			b[1]++;
			c[i] -= 3;
		}
	}
	if (m > 1)
	{
		for (int i = 1; i < m; i++)
		{
			b[i]++;
			if (b[i] >= 3 && i != m - 1)
			{
				b[i] -= 3;
				b[i + 1]++;
			}
			if (b[i] >= 3 && i == m - 1)
			{
				b[i] -= 3;
				printf("1");
			}
		}
		for (int i = m - 1; i >= 1; i--)
		{
			b[i]--;
			if (b[i] < 0)  b[i] = 2;
			printf("%d", b[i]);
		}
	}
	else printf("%d", b[1]);
	if (n > 1)
	{
		printf(".");
		for (int i = 1; i < n; i++)
		{
			c[i]--;
			if (c[i] < 0)  c[i] = 2;
			printf("%d", c[i]);
		}
	}
	return 0;
}