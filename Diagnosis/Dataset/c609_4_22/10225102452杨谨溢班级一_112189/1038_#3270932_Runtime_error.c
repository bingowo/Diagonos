#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int cmp(const void* a, const void* b)
{
	char* A = (char*)a;
	char* B = (char*)b;
	return strcmp(A, B);
}

char WORDS[300][500] = {0};
int main()
{
	int T;
	scanf("%d\n", &T);
	for (int t = 0; t < T; ++t)
	{
		char c = 0;
		int n = 0;
		char WORDS[300][505] = { 0 };
		int e = 0;
		int i = 0;
		c = getchar();
		while (c != ' ' && c != ',' && c != '?' && c != '.' && c != '!'&&c!='\n')
		{
			WORDS[n][i++] = c;
			c = getchar();
		}
		WORDS[n++][i] = '\0';// 读第一个

		char words[500] = { 0 };
		while ((c = getchar()) != '\n')
		{
			if (c == ' '|| c == ','||c == '?'||c == '.'||c=='!')
			{
				if (words[0] == 0)  continue;
				words[e] = 0;
				int f = 1;
				for (int j = 0; j < n; ++j)
				{
					if (strcmp(words, WORDS[j])==0)
					{
						f = 0;
						break;
					}
				}
				if (f)
				{
					int len = strlen(words);
					for (int j = 0; j <= len; ++j) 
					{
						WORDS[n][j] = words[j];
						words[j] = 0;
					}
					n++;
				}
				e = 0;
				continue;
			}
			else
			{
				words[e++] = c;
			}
		}
		qsort(WORDS, n, sizeof(WORDS[0]), cmp);
		//printf("%d size\n", sizeof(WORDS[0]));
		printf("case #%d:\n", t);
		for (int i = 0; i < n; ++i)
		{
			if (i == n - 1)  printf("%s\n", WORDS[i]);
			else printf("%s ", WORDS[i]);
		}
	}
	return 0;
}