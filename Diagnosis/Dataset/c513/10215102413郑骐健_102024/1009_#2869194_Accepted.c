#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int cmp(int a,int b)
{
	return (a % b == 0) ? b : cmp(b, a % b);
}
int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n;i++)
	{
		int up = 0, down;
		char c;
		int p = 0;
		while ((c = getchar()) != '\n')
		{
			p++;
			int a = 1;
			for (int z = 0;z < 8;z++)
			{
				if ((a << z) & (c))
				{
					up++;
				}
			}
		}
			down = p * 8;
			printf("%d/%d\n", up / (cmp(up, down)), down / cmp(up, down));
		

	}
		return 0;
}