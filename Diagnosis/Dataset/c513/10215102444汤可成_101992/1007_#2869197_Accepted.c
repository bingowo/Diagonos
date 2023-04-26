#include<stdio.h>

int len(int n)
{
	int i = 31;
	int num = 1;
	int max = 1;
	while (((n >> i) & 1) == 0)
	{
		i--;
	}
	i--;
	while (i >= 0)
	{
		if (((n >> (i + 1)) & 1) ^ ((n >> i) & 1))
		{
			num++;
		}
		else
		{
			max = num > max ? num : max;
			num = 1;
		}
		i--;
	}
	max = num > max ? num : max;
	return max;
}

int main()
{
	int T = 0;
	scanf("%d", &T);
	int i = 0;
	for (i = 0; i < T; i++)
	{
		int n = 0;
		scanf("%d", &n);
		printf("case #%d:\n", i);
		printf("%d\n", len(n));
	}
	return 0;
}