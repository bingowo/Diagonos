#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 50
int Max(int a, int b)
{
	return a > b ? a : b;
}
int fencelen(char* s)
{
	char* p = s;
	if (!*p) return 0;
	while (*(p+1)&&*p != *(p + 1))
		p++;
	return Max(p + 1 - s, fencelen(p + 1));
}
int main()
{
	char s[N+1];
	fgets(s, sizeof(s), stdin);
	if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = 0;
	int len=fencelen(s);
	printf("%d\n", len);
}