#include<stdio.h>
#include<string.h>
#include<stdlib.h>        

void solveint(int a)
{
	int n = sizeof(a);
	unsigned char* p = (unsigned char*)&a;
	while (n--) {
		printf("%02x ", *p++);
	}
	printf("\n");
}

void solvedouble(double a)
{
	int n = sizeof(a);
	unsigned char* p = (unsigned char*)&a;
	while (n--) {
		printf("%02x ", *p++);
	}
	printf("\n");
}

int main()
{
	char s[100][100];
	int i = 0;
	for (int i = 0;scanf_s("%s", &s[i],100) != EOF;i++)
	{
		if (strchr(s[i], '.'))
		{
			solvedouble(atof(s[i]));
		}
		else
		{
			solveint(atoi(s[i]));
		}
	}
	return 0;
}
