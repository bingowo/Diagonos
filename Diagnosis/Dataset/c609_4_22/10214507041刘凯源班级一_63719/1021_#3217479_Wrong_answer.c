#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define min(a, b) (a > b ? b : a)
int id[300];
char model[110];
char s[105][25];
int cmp(void *a, void *b)
{
	char *p1 = a;
	char *p2 = b;
	int len1 = strlen(p1);
	int len2 = strlen(p2);
	for(int i = 0; i < min(len1, len2); ++i)
	{
		if(p1[i] != p2[i])
			return id[p1[i]] - id[p2[i]];
	}
	return len1 - len2;
}
int main()
{
	while(scanf("%s", model + 1) != EOF)
	{
		memset(s, 0, sizeof(s));
		char c = getchar();
//		printf("%s\n", model + 1);
		int n = 0, i = 0;
		while((c = getchar()) != '\n')
		{
			if(c == ' ')
			{
				s[n][i] = '\0';
				++n;
				i = 0;
			}
			else
			{
				s[n][i++] = c;
			}
		}
//		for(int i = 0; i <= n; ++i)
//		{
//			printf("%s\n", s[i]);
//		}
		for(int i = 1; i <= 26; ++i)
		{
			id[model[i]] = i;
			id[model[i] + 32] = i;
		}
		qsort(s, n + 1, sizeof(char) * 25, cmp);
		for(int i = 0; i <= n; ++i)
		{
			printf("%s%c", s[i], (i == n ? '\n' : ' '));
		}
	}
	
}