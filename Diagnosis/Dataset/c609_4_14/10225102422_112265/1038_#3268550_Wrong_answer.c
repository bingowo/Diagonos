#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 500
int is(char M[N + 1][N + 1], char X[N + 1], int k)
{
	if (k == 0) return 1;
	for (int i = 0; i < k; i++)
	{
		if (strcmp(M[i], X) == 0)
			return 0;
	}
	return 1;
}
int cmp(const void* e1, const void* e2)
{
	char *p1 = *(char**)e1;
	char* p2 = *(char**)e2;
	return strcmp(p1, p2);
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
		for (int j = 0; s[j] != '\n';j++)
		{
			int x = 0;
			for (; (s[j] != ' ') && (s[j] != '.') && (s[j] != ',') && (s[j] != '?') && (s[j] != '!')&&(s[j]!='\n'); j++, x++)
			{
				M[k][x] = s[j];

			}
			if ((s[j-1] != ' ') && (s[j-1] != '.') && (s[j-1] != ',') && (s[j-1] != '?') && (s[j-1] != '!')&&(s[j]!='\n'))
			{
				M[k][x] = 0; k++;
			}

		}
		int len = k; int j;
		for (k = 0, j = 0; k < len; k++)
		{
			int temp = is(M, M[k], k);
			if (temp == 1)
			{
				H[j] = M[k];
				j++;
			}
		}
		if(j==1) {
		    printf("case #%d:\n", i);
		    	printf("%s ", H[0]);
		}
		else{
		qsort(H, j, sizeof(H[0]), cmp);
		printf("case #%d:\n", i);
		for (k = 0; k < j; k++)
			printf("%s ", H[k]);}
		printf("\n");
	}
	return 0;
}