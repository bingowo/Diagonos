#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define min(a, b) (a >= b ? b : a)
const int MAXN = 1e6 + 10;
char *email[1000005];
char s[1000005];
int n;
//strcmp();
int cmps(char *s1, char *s2)
{
	size_t len1 = strlen(s1);
	size_t len2 = strlen(s2);
	for(int i = 0; i < min(len1, len2); ++i)
	{
		if(s1[i] != s2[i])
		{
			return s1[i] - s2[i];
		}
	}
	return len1 - len2;
}
int cmp(const void *p1, const void *p2)
{
	char *s1, *s2, *domain1, *domain2;
	s1 = *((char**)p1);
	s2 = *((char**)p2);
	for(int i = 0; i <= strlen(s1); ++i)
	{
		if(s1[i] == '@')
		{
			domain1 = s1 + i + 1;
		}
	}
	for(int i = 0; i <= strlen(s2); ++i)
	{
		if(s2[i] == '@')
		{
			domain2 = s2 + i + 1;
		}
	}
	return strcmp(domain1, domain2) == 0 ? -strcmp(s1, s2) : strcmp(domain1, domain2);
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%s", s);
		int len = strlen(s);
		char *p;
		p = (char*)malloc((len + 1) * sizeof(char));
		strcpy(p, s);
		email[i] = p;
	}
//	printf("%d", 1);
	qsort(email + 1, n, sizeof(char*), cmp);
	for(int i = 1; i <= n; ++i)
	{
		printf("%s\n", email[i]);
	}
	for(int i = 1; i <= n; ++i)
	{
		free(email[i]);
	}
}