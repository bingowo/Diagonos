#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100
char Base[64] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-' };


int btoi(int n, char L[8*(N + 1)],int LEN,int yu)
{
	int i = 0; int num = 0;
	for (i = 0; i < 6&&(n<LEN-1); i++)
		num = num * 2 + (L[n * 6 + i] - '0');
	if((n==LEN-1)&&(yu==0))
	{
	    for (i = 0; i < 6; i++)
		num = num * 2 + (L[n * 6 + i] - '0');
	}
	else if((n==LEN-1)&&yu!=0)
	{
	    for (i = 0; i < yu; i++)
		num = num * 2 + (L[n * 6 + i] - '0');
		for(i=0;i<6-yu;i++)
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
		char s[N + 1] ;
		scanf("%s",s);
		int LEN;
		int len = strlen(s);
		char L[8*(N + 1)];
		int M[N * 4 / 3 + 2];
		char G[N * 4 / 3 + 2];
		if ((len * 8) % 6 == 0)
		{
			LEN = len * 8 / 6;
			for (int j = 1; j <= len; j++)
		{
			int m = (int)s[j]; int k =0 ;
			for (k = 0; m != 0; k++, m /=2)
			{	L[j * 8 - 1 - k] = (m % 2 + '0');
			}
			for (; k < 8; k++)
				L[j * 8 - 1 - k] =  '0';
			if (LEN< 4)
			{
				int j;
				for (j = 0; j < LEN;j++)
				{
					M[j] = btoi(j, L,LEN,0);
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
					M[j] = btoi(j, L,LEN,0);
					G[j] = Base[M[j]];
				}
			}
		}
		else
		{

			LEN = len * 8 / 6 + 1;
			int yu=len*8%6;
			for (int j = 1; j <= len; j++)
		{
			int m = (int)s[j]; int k =0 ;
			for (k = 0; m != 0; k++, m /=2)
			{	L[j * 8 - 1 - k] = (m % 2 + '0');
			}
			for (; k < 8; k++)
				L[j * 8 - 1 - k] =  '0';
			if (LEN< 4)
			{
				int j;
				for (j = 0; j < LEN; j++)
				{
					M[j] = btoi(j, L,LEN,yu);
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
					M[j] = btoi(j, L,LEN,yu);
					G[j] = Base[M[j]];
				}
			}
		}
		printf("case #%d:\n", i);
		for (int j = 0; j < LEN; j++)
			printf("%c", G[j]);
		printf("\n");
	}
	return 0;
}