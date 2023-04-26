#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 105
char s[MAXN];
int num[MAXN], len, len_num;
int ans[MAXN], tot;
int digit;
int main()
{
	scanf("%s", s + 1);
	len = strlen(s + 1);
	int i = 1;
	if(s[i] == '-')
	{
		++i;
		digit = 1;
	}
	for(i; i <= len; ++i)
	{
		num[++len_num] = s[i] - '0';
	}
	while(1)
	{
		int yu = 0;
		int tmpnum[MAXN];
		int tmplen = 0;
		memset(tmpnum, 0, sizeof(tmpnum));
		for(int i = 1; i <= len_num; ++i)
		{
			int now = 10 * yu + num[i];
			tmpnum[++tmplen] = now >> 1;
			yu = now & 1;
		}
		ans[++tot] = yu;
		if(digit && yu)//add 1
		{
			tmpnum[tmplen] += 1;
			for(int i = tmplen; i >= 0; --i)
			{
				if(tmpnum[i] >= 10)
				{
					tmpnum[i] -= 10;
					tmpnum[i - 1] += 1;
				}
				else
				{
					break;
				}
			}
		}
		digit ^= 1;
		memset(num, 0, sizeof(num));
		len_num = 0;
		int has = 0;
		for(int i = 0; i <= tmplen; ++i)
		{
			if(tmpnum[i] != 0)
			{
				has = 1;
			}
			if(has)
			{
				num[++len_num] = tmpnum[i];
			}
		}
		if(!len_num)
			break;
	}
	for(int i = tot; i >= 1; --i)
		printf("%d", ans[i]);
}
