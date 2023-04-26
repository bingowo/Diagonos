#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int a = 1;//掩码
	int T;
	scanf("%d", &T);
	for (int i = 0;i < T;i++)
	{
		int x, y, n = 0;
		scanf("%d%d", &x, &y);
		for(int z = 0;z<32;z++)
		{
			if (((a << z) & x) ^ ((a << z) & y))
			{
				n++;
			}
		}
		printf("%d\n", n);
	}
		return 0;
}