#include<stdio.h>
#include<string.h>
int getnum(char x)
{
	if(x == '0')
		return 0;
	else if(x == '1')
		return 1;
	else if(x == '-')
		return -1;
}
char s[10000000];
int sov()
{
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	long long ans = 0;
	for(int i = 1; i <= len; ++i)
		ans = ans * 3 + getnum(s[i]);
	printf("%lld\n", ans);
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