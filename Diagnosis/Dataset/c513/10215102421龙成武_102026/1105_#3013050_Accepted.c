#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	int W, H, ** mt, i, j, bin[20], temp,min, x, y;
	scanf("%d %d", &W, &H);
	mt = (int**)malloc(H * sizeof(int*));
	for (i = 0;i < H;i++)
	{
		mt[i] = (int*)malloc(W * sizeof(int));
		for (j = 0;j < W;j++)
		{
			scanf("%d", &mt[i][j]);
		}
	}
	for (i = 1;i < H - 1;i++)
	{
		for (j = 1;j < W - 1;j++)
		{
			bin[0] = mt[i - 1][j - 1] >= mt[i][j];
			bin[1] = mt[i - 1][j] >= mt[i][j];
			bin[2] = mt[i - 1][j + 1] >= mt[i][j];
			bin[3] = mt[i][j + 1] >= mt[i][j];
			bin[4] = mt[i+1][j + 1] >= mt[i][j];
			bin[5] = mt[i + 1][j] >= mt[i][j];
			bin[6] = mt[i + 1][j-1] >= mt[i][j];
			bin[7] = mt[i ][j -1] >= mt[i][j];

			bin[8] = mt[i - 1][j - 1] >= mt[i][j];
			bin[9] = mt[i - 1][j] >= mt[i][j];
			bin[10] = mt[i - 1][j + 1] >= mt[i][j];
			bin[11] = mt[i][j + 1] >= mt[i][j];
			bin[12] = mt[i + 1][j + 1] >= mt[i][j];
			bin[13] = mt[i + 1][j] >= mt[i][j];
			bin[14] = mt[i + 1][j - 1] >= mt[i][j];
			bin[15] = mt[i][j - 1] >= mt[i][j];
			min = 1000000;
			for (x = 0;x < 8;x++)
			{
				temp = 0;
				for (y = x;y < x + 8;y++)
				{
					temp = temp * 2 + bin[y];
				}
				min = temp < min ? temp : min;
			}
			printf("%d", min);
			if (j == W - 2)
				printf("\n");
			else
				printf(" ");
		}
	}


	for (i = 0;i < H;i++) free(mt[i]);
	free(mt);
	return 0;
}