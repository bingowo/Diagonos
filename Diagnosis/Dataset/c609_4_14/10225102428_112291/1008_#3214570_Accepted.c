#include <stdio.h>
#include<string.h>
#include <stdlib.h>
void f1(int n);
void f2(double n);
int main() {
	char s[31];
	while (scanf("%s",s)!=EOF)
	{
		if (strchr(s, '.') == 0) 
			f1(atoi(s));
		else
		{
			f2(atof(s));
		}
	}
	return 0;
}
void f1(int n) {
	int c = sizeof(n);
	unsigned char *p = (unsigned char *)&n;
	while (c--)
	{
		printf("%02x ", *p++);
	}
	printf("\n");
}
void f2(double n)
{
	int c = sizeof(n);
	unsigned char *p = (unsigned char *)&n;
	while (c--)
	{
		printf("%02x ", *p++);
	}
	printf("\n");
}