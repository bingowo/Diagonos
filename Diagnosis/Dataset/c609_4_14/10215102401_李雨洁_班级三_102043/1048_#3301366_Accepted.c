#include <stdio.h>
void f(int n)
{
	int first[10000] = { 0 };
	int second[10000] = { 0 };
	memset(first, 0, 10000);
	memset(second, 0, 10000);
	int tmp[10000] = { 0 };
	if (n == 0)
	{
		printf("0\n");
		return;
	}
	if (n == 1 || n == 2)
	{
		printf("1\n");
		return;
	}
	if (n == 3)
	{
		printf("2\n");
		return;
	}
	first[1] = 1; first[0] = 1;
	second[1] = 2; second[0] = 1;
	for (int i = 3; i < n; i++)
	{
		int in = 0; //进位标志
		memset(tmp, 0, 10000);
		for (int j = 1; j <= second[0]; j++)
		{
			int m = (first[j] + second[j] + in);
			tmp[j] = m % 10;
			tmp[0] += 1;
			in = 0;
			if (m / 10) in = 1;
		}
		if (in)
		{
			tmp[0] += 1;
			tmp[tmp[0]] = 1;
		}
		for (int j = second[0]; j >= 0; j--)
			first[j] = second[j];
		for (int j = tmp[0]; j >= 0; j--)
			second[j] = tmp[j];
	}
	for (int i = second[0]; i > 0; i--)
		printf("%d", second[i]);
	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	int n;
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		printf("case #%d:\n", i);
		f(n);
	}
	return 0;
}