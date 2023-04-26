#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 500
int is(char M[N + 1][N+1], char X[N + 1],int k)
{
	if (k == 0) return 1;
	for (int i = 0; i < k; i++)
	{
		if (strcmp(M[i], X) == 0)
			return 0;
	}
	return 1;
}
int main()
{
	int T;
	scanf("%d\n", &T);
	char s[N + 1];
	char M[N + 1][N + 1];
	char* H[N + 1];
	for (int i = 0; i < T; i++)
	{
		fgets(s, N + 1, stdin);
		int k = 0;
		for (int j = 0; s[j] != '\n';k++,j++)
		{
			int x = 0;
			for (; (s[j] != ' ') && (s[j] != '.') && (s[j] != ',') &&(s[j] != '?') && (s[j] != '!'); j++,x++)
			{
				M[k][x] = s[j];

			}
			M[k][x] = 0;

		}
		int len = k; int j;
		for (k = 0,j=0; k < len; k++)
		{
			int temp = is(M, M[k],k);
			if (temp == 1)
			{
				H[j] = M[k];
				j++;
			}
		}
		printf("case #%d:\n", i);
		for (k = 0; k < j; k++)
			printf("%s ", H[k]);
		printf("\n");
	}
	return 0;
}