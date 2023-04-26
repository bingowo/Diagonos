#include<stdio.h>
#include<string.h>
int getnum(char x)
{
	if('0' <= x && x <= '9')
	{
		return x - '0';
	}
	else if('a' <= x && x <= 'z')
	{
		return x - 'a' + 10;
	}
	else
	{
		return x - 'A' + 10;
	}
}
char get_char(int x)
{
	if(x <= 9)
		return '0' + x;
	else
		return 'A' + x - 10;
}
char s[1000000];
char ans[1000000];
long long a,b,x,tot;
int main()
{
	scanf("%lld", &a);
	scanf("%s", s + 1);
	scanf("%lld", &b);
	int len = strlen(s + 1);
	long long tmp = 1;
	for(int i = len; i >= 1; --i)
	{
		x += tmp * getnum(s[i]);
		tmp = tmp * a;
	}
	if(x == 0)
	{
		puts("0");
		return 0;
	}
	while(x)
	{
		ans[++tot] = get_char(x % b);
		x /= b;
	}
	for(int i = tot; i >= 1; --i)
		putchar(ans[i]);
		
}