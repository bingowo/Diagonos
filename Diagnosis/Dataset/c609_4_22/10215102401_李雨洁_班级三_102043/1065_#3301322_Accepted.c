#include <stdio.h>
#include <stdlib.h>
double f()//计算波兰表达式（只有加减乘除无括号）
{
	char s[101];
	scanf("%s", s);
	if (s[0] == '+')
		return f() + f();
	else if (s[0] == '-')
		return f() - f();
	else if (s[0] == '*')
		return f() * f();
	else if (s[0] == '/')
		return f() / f();
	else
		return atof(s);//转为浮点数
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		printf("case #%d:\n", i);
		printf("%.6f\n", f());
	}
	return 0;
}