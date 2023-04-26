#include<stdio.h>
#include<string.h>
char s[100005];
unsigned int ans[100005], tot;
int ctom(char x)
{
	if(x <= '9' && x >= '0')
		return x - '0';
	else
		return x - 'a' + 10;
}
int is(char x)
{
	return ('0' <= x && x <= '9') | ('a' <= x && x <= 'f');
}
int main()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	int innum = 0, hasnum = 0;
	unsigned int num = 0;
	for(int i = 2; i <= n; ++i)
	{
		if(s[i] == 'x' && i > 1 && s[i - 1] == '0')
		{
			innum = 1;
		}
		else if(innum)
		{
			if(is(s[i]))
			{
				hasnum = 1;
				num = num * 16 + ctom(s[i]);
			}
			else
			{
				if(hasnum)
					ans[++tot] = num;
				num = 0;
				hasnum = innum = 0;
			}
		}
//		printf("%c %d %d %d %d\n", s[i], innum, hasnum, num, is(s[i]));
	}
	if(hasnum)
		ans[++tot] = num;
	for(int i = 1; i <= tot; ++i)
		printf("%u ", ans[i]);
	if(!tot)
		puts("-1");
}