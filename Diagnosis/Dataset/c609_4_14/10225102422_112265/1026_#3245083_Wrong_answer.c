
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct str
{
	char string[21];
	int num;
};
int cmp(const void* e1, const void* e2)
{
	int p1 = *(int*)e1;
	int p2 = *(int*)e2;
	return p1 - p2;
}
int num(char s[21])
{
	qsort(s, strlen(s), sizeof(char), cmp);
	int count = 1;
	for (int i = 0; i < strlen(s)-1; i++)
	{
		if (s[i] != s[i + 1])
			count++;
	}
	return count;
}
int CMP(const void* e1, const void*e2)
{
	struct str p1 = *(struct str*)e1;
	struct str p2 = *(struct str*)e2;
	if (p1.num != p2.num)
		return p2.num - p1.num;
	else
	{
		return strcmp(p1.string, p2.string);
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int n;
		scanf("%d", &n);
		struct str* S = (struct str*)malloc(sizeof(struct str)*n);
		for (int j = 0; j < n; j++)
		{
			scanf("%s", S[j].string);
			S[j].num=num(S[j].string);

		}
		qsort(S, n, sizeof(S[0]), CMP);
		printf("case #%d:\n", i);
		for (int j = 0; j < n; j++)
			printf("%s\n", S[j].string);
		free(S);
	}
	return 0;
}