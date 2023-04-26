#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 10e6
struct dex
{
	int index;
	int len;
};
int flag(char c, int i, char*s,int index)
{
	int j;
	if (i == index) return 1;
	for (j = index; j < i; j++)
	{
		if (c == s[j])
			return 0;
	}
	return 1;
}
int begin(char c, int i, char*s, int index)
{
	int j;
	if (i == index) return 1;
	for (j = index; j < i; j++)
	{
		if (c == s[j])
			return j;
	}
	return -1;
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
		for (int i = 0; i < strlen(s);)
		{
			l[j].index = i;
			int count = 0;
			if (flag(s[i], i, s,l[j].index))
			{
				for (; flag(s[i], i, s,l[j].index); i++)
				{
					count++;
				}
				l[j].len = count;
			}
			if (flag(s[i], i, s, l[j].index)==0)
			{
				int in = begin(s[i], i, s, l[j].index);
				i = in + 1;
			}
			j++;
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