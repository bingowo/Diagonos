#include<stdio.h>
#include<string.h>
int A()
{ 
	char c1, c2; int num = 0;
	if (c1 = getchar() == '(')
	{
		if (c2 = getchar() == '(')
		{
			ungetc(c2, stdin);
			num = 2 * A();
		}
		else num = 1;
		if (c1 = getchar() != '\n')
			num += A();
	}
	return num;
}
int main()
{
	priintf("%d\n", A());
	return 0;
}