#include <stdlib.h>
#include<stdio.h>
#include<string.h>
double eval()
{
	char s[11];
	double f1, f2;
	scanf("%s", s);
	switch (s[0])
	{
		case '+':f1 = eval(); f2 = eval(); return f1 + f2;
		case '-':f1 = eval(); f2 = eval(); return f1 - f2;
		case '*':f1 = eval(); f2 = eval(); return f1 * f2;
		case '/':f1 = eval(); f2 = eval(); return f1 / f2;
		default:return atof(s);
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		printf("case #%d\n",i);
		printf("%.6f\n", eval());
	}
	return 0;
}
