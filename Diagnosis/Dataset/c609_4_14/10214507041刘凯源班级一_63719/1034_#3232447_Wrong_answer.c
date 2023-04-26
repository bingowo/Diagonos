#include<stdio.h>
#include<string.h>
char s[100005];
int char_num(char x)
{
	if(x <= '9' && x >= '0')
		return x - '0';
	else
		return x - 'a' + 10;
}
int is(char x)
{
	return ('0' <= x && x <= '9') || ('a' <= x && x <= 'f');
}
int main()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	int id = 0;
	unsigned int num = 0;
	int cnt = 0;
	for(int i = 1; i <= n; ++i)
	{
		if(s[i] == '0' && s[i + 1] == 'x')
		{
			if(id)
			{
				printf("%u ", num);
				num = 0;
				++cnt;
			}
			id = 1;
			++i;
		}
		else if(id && is(s[i]))
		{
			num = num * 10 + char_num(s[i]);
		}
	}
	if(num)
	{
		printf("%d", num);
		++cnt;
	}
	if(!cnt)
		puts("-1");
}