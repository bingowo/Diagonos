#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct
{
	char word[500];
	//int exist;
}WORD;

int cmp(const void* a, const void* b)
{
	WORD A = *(WORD*)a, B = *(WORD*)b;
	//if (A.exist == 0 || B.exist == 0)  return 0;
	/*if (strcmp(A.word, B.word) == 0)
	{
		(*(WORD*)b).exist = 0;
		return 0;
	}*/
	return strcmp(A.word, B.word);
}


int main()
{
	int T;
	scanf("%d\n", &T);
	for (int t = 0; t < T; ++t)
	{
		WORD WORDS[300];
		char c;
		int n = 0;
		c = getchar();
		while (c != '\n')
		{
			if (c == ' ' || c == ',' || c == '?' || c == '.' || c == '!') {
				c = getchar();
				continue;
			}
			int i = 0;
			//WORDS[n].exist = 1;
			while (c != ' ' && c != ',' && c != '?' && c != '.' && c != '!'&& c!='\n')
			{
				WORDS[n].word[i++] = c;
				c = getchar();
			}
			WORDS[n].word[i] = '\0';
			//printf("%s\n", WORDS[n].word);
			n++;
		}
		qsort(WORDS, n, sizeof(WORD), cmp);
		printf("case #%d:\n", t);
		for (int i = 0; i < n; ++i)
		{
			if (i == 0)  printf("%s ", WORDS[i].word);
			else if (strcmp(WORDS[i].word, WORDS[i - 1].word) != 0)   printf("%s ", WORDS[i].word);
			else;
		}
		printf("\n");
	}
	return 0;
}