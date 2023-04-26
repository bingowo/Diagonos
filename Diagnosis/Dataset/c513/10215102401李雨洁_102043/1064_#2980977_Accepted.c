#include <stdio.h>
#include <stdlib.h>

double f()
{
    char s[10001];
    scanf("%s",s);
	if (s[0] == '+')
		return f() + f();
	else if (s[0] == '-')
		return f() - f();
	else if (s[0] == '*')
		return f() * f();
	else if (s[0] == '/')
		return f() / f();
	else
		return atof(s);
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++)
    {
        printf("case #%d:\n",i);
        printf("%lf\n", f());
    }
	return 0;
}
