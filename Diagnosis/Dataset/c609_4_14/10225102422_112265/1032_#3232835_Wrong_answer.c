#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 55
int Max(int a, int b)
{
	return a > b ? a : b;
}
int fencelen(char* s)
{
	char* p = s;
	int i = 0;
	if (!*p)return 0;
	while (*p&&*(p + 1) != *(p + 1))
		p++;
	return Max(p + 1 - s, fencelen(p + 1));
}
int main()
{
	char s[N];
	fgets(s,N,stdin);
	if(s[strlen(s)-1]=='\n') s[strlen(s)-1]=0;
	int len=fencelen(s);
	printf("%d\n", len);
}