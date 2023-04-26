#include<stdio.h>

int count(int m, int n)
{
	int num = 0;
	int ret = 0;
	num = m ^ n;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if ((num >> i) & 1)
		{
			ret++;
		}
	}
	return ret;
}

int main()
{
	int T = 0;
	scanf("%d", &T);
	int i = 0;
	for (i = 0; i < T; i++)
	{
		int m = 0;
		int n = 0;
		scanf("%d %d", &m, &n);
		printf("%d\n", count(m, n));
	}
	return 0;
}