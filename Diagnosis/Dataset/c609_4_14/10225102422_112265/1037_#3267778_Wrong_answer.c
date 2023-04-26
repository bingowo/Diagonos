#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 10e6
struct dex
{
	int index;
	int len;
};
int cmp(const void* e1, const void* e2)
{
	struct dex p1 = *(struct dex*)e1;
	struct dex p2 = *(struct dex*)e2;
	if (p1.len != p2.len)
		return p2.len - p1.len;
	else
		return p1.index - p2.index;
}
int main()
{
	char* s = (char*)malloc(sizeof(char)*(N+1));
	scanf("%s", s);
	struct dex* m = (struct dex*)malloc(sizeof(struct dex)*N);
	int i; int j;
	for (i = 0,j=0; i < strlen(s)-1;)
	{
		if (s[i] != s[i + 1])
		{
			int count = 1;
			m[j].index = i;
			for (; (s[i] != s[i + 1]) && (i < strlen(s) - 1); i++)
			{
				count++;
			}
			m[j].len = count;
			j++;
		}
		else
			i++;
	}
	qsort(m, j, sizeof(m[0]), cmp);
	int index = m[0].index;
	int length = m[0].len;
	free(m);
	for (i = index; i < index + length; i++)
		printf("%c", s[i]);
	free(s);
	return 0;
}