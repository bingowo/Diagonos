#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define min(a, b) (a < b ? a : b)
char s[101][40];
int cmp(void *p1, void *p2)
{
	char *s1, *s2;
	s1 = (char*)p1;
	s2 = (char*)p2;
	int num1 = 0, num2 = 0;
	int len1 = strlen(p1);
	int len2 = strlen(p2);
	int hasnum1 = 0, hasnum2 = 0;
	for(int i = 0; i < len1; ++i)
	{
		if(isdigit(s1[i]))
			hasnum1 = 1, num1 = num1 * 10 + s1[i] - '0';
	}
	for(int i = 0; i < len2; ++i)
	{
		if(isdigit(s2[i]))
			hasnum2 = 1, num2 = num2 * 10 + s2[i] - '0';
	}
//	printf("%d %d", num1, num2);
	if(hasnum1 && hasnum2)
	{
		return num1 - num2;
	}
	else if(hasnum1 || hasnum2)
	{
		return hasnum1 - hasnum2;
	}
	else
	{
		return strcmp(s1, s2);
	}
}
int main()
{
	int i = 0;
//	cmp("abc2", "abc10");
//	return 0;
	while(scanf("%s", s[++i]) != EOF)
	{
		
	}
	qsort(s + 1, i - 1, sizeof(char) * 40, cmp);
	for(int j = 1; j < i; ++j)
		printf("%s ", s[j]);
}