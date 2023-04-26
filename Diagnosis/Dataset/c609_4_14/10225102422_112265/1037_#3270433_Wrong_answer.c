#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 10e6
struct dex
{
	int index;
	int len;
};
int flag(char c, int i, char*s)
{
	int j;
	if (i == 0) return 1;
	for (j = 0; j < i; j++)
	{
		if (c == s[j])
			return 0;
	}
	return 1;
}
int cmp(const void* e1, const void* e2)
{
	struct dex p1 = *(struct dex*)e1;
	struct dex p2 = *(struct dex*)e2;
	if (p1.len != p2.len)
		return p2.len - p1.len;
	else return p1.index - p2.index;
}
int main()
{
	char* s = (char*)malloc(sizeof(char)*(N + 1));
	fgets(s, N + 1, stdin);
	if (s[strlen(s) - 1] == '\n')
		s[strlen(s) - 1] = 0;
	struct dex* l = (struct dex*)malloc(sizeof(struct dex)*(strlen(s) + 1));
	if (strlen(s) == 1) printf("%s", s);
	else
	{
		int j=0;
		for (int i = 0; i < strlen(s) - 1; )
		{
			if ((s[i] != s[i + 1]) && flag(s[i],i,s))
			{
				l[j].index = i; int count = 0;
				for (; (s[i] != s[i + 1]) && flag(s[i], i, s) && (i < strlen(s) - 1);i++)
				{
					count++;
				}
				if (flag(s[strlen(s) - 1], strlen(s) - 1, s))
					count++;
				l[j].len = count;
				j++;
			}
			else if (s[i] == s[i + 1])
			{
				l[j].index = i;
				l[j].len = 1;
				j++;
				i++;
			}
			else if (flag(s[i], i, s) == 0)
				i++;
		}
		int lenth = j;
		qsort(l, lenth, sizeof(l[0]), cmp);
		for (j = l[0].index; j < l[0].index + l[0].len; j++)
			printf("%c", s[j]);
		free(l);
		free(s);
		printf("\n");
	}
	return 0;
}