#include<stdio.h>

int count_one(char c)
{
	int j = 0;
	int num = 0;
	for (j = 0; j < 8; j++)
	{
		if ((c >> j) & 1)
		{
			num++;
		}
	}
	return num;
}

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	getchar();
	int i = 0;
	for (i = 0; i < n; i++)
	{
		char c = 0;
		int num = 0;
		int one = 0;
		while ((c = getchar()) != '\n')
		{
			num++;
			one += count_one(c);
		}
		int m = GCD(one, num * 8);
		printf("%d/%d\n", one/m, num * 8 /m);
	}
}