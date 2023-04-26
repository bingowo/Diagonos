#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
/*typedef struct
{
	char word[500];
	int exist;
}WORD;*/

int cmp(const void* a, const void* b)
{
	//if (A.exist == 0 || B.exist == 0)  return 0;
	/*if (strcmp(A.word, B.word) == 0)
	{
		(*(WORD*)b).exist = 0;
		return 0;
	}*/
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
		char c;
		int n = 0;
		while ((c = getchar()) != '\n')
		{
			if (!isalpha(c))  continue;
			int i = 0;
			//WORDS[n].exist = 1;
			while (isalpha(c))
			{
				WORDS[n][i++] = c;
				c = getchar();
			}
			WORDS[n][i] = '\0';
			//printf("%s\n", WORDS[n].word);
			n++;
		}
		qsort(WORDS, n, sizeof(WORDS[0]), cmp);
		printf("case #%d:\n", t);
		for (int i = 0; i < n; ++i)
		{
			if (i == 0)  printf("%s ", WORDS[i]);
			else if (strcmp(WORDS[i], WORDS[i - 1]) != 0)   printf("%s ", WORDS[i]);
			else;
		}
		printf("\n");
	}
	return 0;
}