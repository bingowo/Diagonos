#include<stdio.h>
#include<string.h>
int getnum(char c)
{
	return c - '0';
}
void sov()
{
	char s[55];
	memset(s, 0, sizeof(s));
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	int p = 1;
	double ans1 = 0, ans2 = 0;
	double tmp = 1.0 / 8.0;
	for(p; p <= len; ++p)
	{
		if(s[p] == '.')
		{
			++p;
			break;
		}
		ans1 = ans1 * 8 + getnum(s[p]);
	}
	for(p; p <= len; ++p)
	{
		ans2 = ans2 + getnum(s[p]) * tmp;
		tmp /= 8.0;
	}
	printf("%f\n", ans1 + ans2);
}
int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i)
	{
		printf("case #%d:\n", i);
		sov();
	}
}