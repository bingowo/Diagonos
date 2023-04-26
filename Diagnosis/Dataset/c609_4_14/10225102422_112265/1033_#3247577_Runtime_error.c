#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100
char Base[64] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-' };


int btoi(int n, char* L[N + 1],int len)
{
	int i = 0; int num = 0;
	for (i = 0; i < 6; i++)
		num = num * 2 + (L[n * 6 + i] - '0');
	if (i<6)
	{
		for (; i <= 6; i++)
			num = num * 2;
	}
	return num;
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		char s[N + 1] ;
		scanf("%s",s);
		int LEN;
		int len = strlen(s);
		char L[N + 1][8];
		int M[N * 4 / 3 + 2];
		char G[N * 4 / 3 + 2];
		if ((len * 8) % 6 == 0)
		{
			LEN = len * 8 / 6;
			for (int j = 0; j < len; j++)
			{
				int m =(int) s[j];
				for (int k = 0; m!=0; k++,m/=2)
					L[j][k] = m % 2 + '0';
			}
			if (LEN< 4)
			{
				int j;
				for (j = 0; j < LEN;j++)
				{
					M[j] = btoi(j, L,len);
					G[j] = Base[M[j]];
				}
				for (; j < 4; j++)
					G[j] = '=';
			}
			else
			{
				int j;
				for (j = 0; j < LEN; j++)
				{
					M[j] = btoi(j, L,len);
					G[j] = Base[M[j]];
				}
			}
		}
		else
		{
			
			LEN = len * 8 / 6 + 1;
			for (int j = 0; j < len; j++)
			{
				int m =(int) s[j];
				for (int k = 0; m != 0; k++, m/=2)
					L[j][k] =(m%2+'0') ;
			}
			if (LEN< 4)
			{
				int j;
				for (j = 0; j < LEN; j++)
				{
					M[j] = btoi(j, L,len);
					G[j] = Base[M[j]];
				}
				for (; j < 4; j++)
					G[j] = '=';
			}
			else
			{
				int j;
				for (j = 0; j < LEN; j++)
				{
					M[j] = btoi(j, L,len);
					G[j] = Base[M[j]];
				}
			}
		}
		printf("case #%d:\n", i);
		for (int j = 0; j < LEN; j++)
			printf("%d", G[j]);
		printf("\n");
	}
	return 0;
}