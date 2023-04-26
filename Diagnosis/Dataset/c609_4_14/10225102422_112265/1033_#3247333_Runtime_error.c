#include <stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100
char Base[64] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-' };

char* ctob(char c)
{
	unsigned char m = c;
	char p[8];
	int i = 7;
	while (m != 0)
	{
		p[i] = m % 2;
		m = m / 2;
		i--;
	}
	for (; i >= 0; i--)
		p[i] = 0;
	return p;

}
int btoi(int n, char L[N + 1][8])
{
	int i = 0; int num = 0;
	for (i = 0; i < 6; i++)
		num = num * 2 + (L[n*6+i] - '0');
    if(i<6)
    {
        for(;i<=6;i++)
            num=num*2;
    }
	return num;
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		char s[N + 1]; int LEN;
		scanf("%s", s);
		int len = strlen(s);
		char* L[N + 1];
		int M[N * 4 / 3 + 2];
		char G[N * 4 / 3 + 2];
		if ((len * 8) % 6 == 0)
		{
			LEN = len * 8 / 6;
			for (int j = 0; j < len; j++)
			{
				L[j] = ctob(s[j]);
			}
			if (LEN< 4)
			{
				int j;
				for (j = 0; j < LEN;j++)
				{
					M[j] = btoi(j, L);
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
					M[j] = btoi(j, L);
					G[j] = Base[M[j]];
				}
			}
		}
		else
		{

			LEN = len * 8 / 6 + 1;
			for (int j = 0; j < len; j++)
			{
				L[j] = ctob(s[j]);
			}
			if (LEN< 4)
			{
				int j;
				for (j = 0; j < LEN; j++)
				{
					M[j] = btoi(j, L);
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
					M[j] = btoi(j, L);
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