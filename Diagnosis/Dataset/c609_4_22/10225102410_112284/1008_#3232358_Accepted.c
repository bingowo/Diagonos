#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void solveint(int n);
void solvedouble(double n);
int main() {
	char s[31];
	while (scanf("%s",s)!=EOF)
	{
        if (strchr(s, '.') == 0){
            solveint(atoi(s));
		}
		else
		{
			solvedouble(atof(s));
		}
	}
	return 0;
}
void solveint(int n) {
	int c = sizeof(n);
	unsigned char *p;
	p = (unsigned char *)&n;
	while (c--)
	{
		printf("%02x ", *p++);
	}
	printf("\n");
}
void solvedouble(double n){
	int c = sizeof(n);
	unsigned char *p;
	p = (unsigned char *) &n;
	while (c--)
	{
		printf("%02x ", *p++);
	}
	printf("\n");
}