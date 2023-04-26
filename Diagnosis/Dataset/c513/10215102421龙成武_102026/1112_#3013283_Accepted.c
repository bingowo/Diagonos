#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int dp[5][1001] = { 0 };
void getdp()
{
	int i, j,sum,km;
	for (i = 0;i < 5;i++)
	{
		dp[i][0] = 1;
	}
	for (i = 1;i < 5;i++)
	{
		for (sum = 1;sum < 1001;sum++)
		{
			km = sum / i;
			for (j = 0;j <= km;j++)
			{
				dp[i][sum] += dp[i - 1][sum - j * i];
			}
		}
	}
}
int main()
{
	int T, n;
	scanf("%d", &T);
	getdp();
	while (T--)
	{
		scanf("%d", &n);
		printf("%d\n", dp[4][n]);
	}
	return 0;
}