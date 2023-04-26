#include<stdio.h>
#include<string.h>
#define max(a, b) (a > b ? a : b)
char s[55];
int main()
{
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	int ans = 1;
	int tmp = 0	;
	for(int i = 1; i <= len; ++i)
	{
		if(s[i] != s[i - 1])
			tmp++;
		else
		{
			ans = max(tmp, ans);
			tmp = 1;
		}
	}
	ans = max(tmp, ans);
	printf("%d", ans);
}