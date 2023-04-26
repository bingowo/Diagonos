#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	long number[500] = { 0 }, temp;
	long S[10] = { 0 }, sum[10] = {0};
	int T, N, M, G, i, j, k, t, q, g;
	char num[500] = { 0 };
	scanf("%d", &T);
	for (i = 0; i < T; i++)
	{
		g = 0;
		for (j = 0; j < 500; j++)
		{
			number[i] = 0;
		}
		scanf("%d%d%d", &N, &M, &G);
		for (j = 0; j < M; j++)
		{
			scanf("%ld", &S[j]);
		}
		
		for (j = 0; j < N; j++)
		{
			for ( k= 0; k < 11; k++)
			{
				scanf("%s", &num[j]);
				number[j] = (long)num[j];
			}
			scanf("%d", &t);
			for (k = 0; k < t; k++)
			{
				scanf("%d", &q);
				sum[j] = sum[j] + S[q - 1];
			}
			if (sum[j] >= G)
				g++;
		}
		for (j = 0; j < N-1; j++)
		{
			for (k = j + 1; k < N; k++)
			{
				if (sum[k - 1] < sum[k])
				{
					temp = sum[k - 1]; sum[k - 1] = sum[k]; sum[k] = temp;
					temp = number[k - 1]; number[k - 1] = number[k]; number[k] = temp;
					temp = num[k - 1]; num[k - 1] = num[k]; num[k] = temp;
				}
				if (sum[k - 1] == sum[k])
				{
					if (number[k - 1] > number[k])
					{
						temp = sum[k - 1]; sum[k - 1] = sum[k]; sum[k] = temp;
						temp = number[k - 1]; number[k - 1] = number[k]; number[k] = temp;
						temp = num[k - 1]; num[k - 1] = num[k]; num[k] = temp;
					}
				}
			}
		}
		printf("case #%d:\n", i);
		printf("%d\n", g);
		for (j = 0; j < g; j++)
		{
			printf("%s ", num[j]);
			printf("%d\n", sum[j]);
		}
	}
	return 0;
}