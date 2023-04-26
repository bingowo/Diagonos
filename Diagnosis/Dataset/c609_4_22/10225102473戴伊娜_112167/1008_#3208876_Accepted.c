#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solveint(int n) {
	int c = sizeof(n);
	unsigned char *p = (unsigned char *)&n;
	while (c--)
	{
		printf("%02x ", *p++);
	}
	printf("\n");
}
void solvedoub(double n)
{
	int c = sizeof(n);
	unsigned char *p = (unsigned char *)&n;
	while (c--)
	{
		printf("%02x ", *p++);
	}
	printf("\n");
}
int main() {
	char s[31];
	while (scanf("%s",s)!=EOF)
	{
		if (strchr(s, '.') == 0) 
			solveint(atoi(s));
		else
		{
			solvedoub(atof(s));
		}
	}
	return 0;
}
