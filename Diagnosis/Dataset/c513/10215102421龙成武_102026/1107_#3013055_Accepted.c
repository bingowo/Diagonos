#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	int i, j, x, T, m;
	scanf("%d", &T);
	for (x = 0;x < T;x++)
	{
		printf("case #%d:\n", x);
		int lamp[3][3] = { 1,1,1,1,1,1,1,1,1 };
		for (i = 0;i < 9;i++)
		{
			scanf("%d", &m);
			while (m--)
			{
				if (i == 0)
				{
					lamp[0][0] ^= 1;lamp[0][1] ^= 1;lamp[1][0] ^= 1;
				}
				else if (i == 1)
				{
					lamp[0][0] ^= 1;lamp[0][1] ^= 1;lamp[0][2] ^= 1;lamp[1][1] ^= 1;
				}
				else if (i == 2)
				{
					lamp[0][2] ^= 1;lamp[0][1] ^= 1;lamp[1][2] ^= 1;
				}
				else if (i == 3)
				{
					lamp[1][0] ^= 1;lamp[0][0] ^= 1;lamp[2][0] ^= 1;lamp[1][1] ^= 1;
				}
				else if (i == 4)
				{
					lamp[1][1] ^= 1;lamp[0][1] ^= 1;lamp[1][0] ^= 1;lamp[1][2] ^= 1;lamp[2][1] ^= 1;
				}
				else if (i == 5)
				{
					lamp[1][2] ^= 1;lamp[0][2] ^= 1;lamp[2][2] ^= 1;lamp[1][1] ^= 1;
				}
				else if (i == 6)
				{
					lamp[2][0] ^= 1;lamp[1][0] ^= 1;lamp[2][1] ^= 1;
				}
				else if (i == 7)
				{
					lamp[2][1] ^= 1;lamp[2][0] ^= 1;lamp[2][2] ^= 1;lamp[1][1] ^= 1;
				}
				else if (i == 8)
				{
					lamp[2][2] ^= 1;lamp[1][2] ^= 1;lamp[2][1] ^= 1;
				}
			}
		}
		for (i = 0;i < 3;i++)
		{
			for (j = 0;j < 3;j++)
			{
				printf("%d", lamp[i][j]);
				if (j == 2)
					printf("\n");
				else
					printf(" ");
			}
		}
	}
	return 0;
}