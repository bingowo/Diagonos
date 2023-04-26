#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void solveint(int n);
void solvedouble(double d);
int main()
{
	char s[1005];
	while(scanf("%s",s)!=EOF)
	{
		if(strchr(s,'.')==0)
			solveint(atoi(s));
		else
			solvedouble(atof(s));
	}
	return 0;
}
void solveint(int n)
{
	int c=sizeof(n);
	unsigned char* p=(unsigned char*)&n;
	while(c--)printf("%02x",*p++);
	printf("\n");
}
void solvedouble(double d)
{
	int c=sizeof(d);
	unsigned char* p=(unsigned char*)&d;
    while(c--)printf("%02x",*p++);
	printf("\n");
}