#include<stdio.h>
#include<string.h>
#define max(a, b) ( a > b ? a : b)
int calc(char *s, int len)
{
//	for(int i = 1; i <= len; ++i)
//		putchar(s[i]);
//	putchar('\n');
	int rlen = len;
	char sta[105];
	int tot = 0;
	int candel = 1;
	while(candel)
	{
		candel = 0;
		tot = 0;
		for(int i = 1; i <= len; ++i)
		{
			if(s[i - 1] == s[i] || s[i + 1] == s[i])
			{
				candel = 1;
				continue;
			}
			sta[++tot] = s[i];
		}
		memset(s, 0, sizeof(s));
		len = tot;
		for(int i = 1; i <= tot; ++i)
			s[i] = sta[i];
	}
	int ans = rlen - tot;
	return ans;
}
void copy(char *s1, char *s2, int id, int len, char x)
{
	for(int i = 1; i <= len; ++i)
		s1[i] = s2[i];
	s1[id] = x;
	for(int i = id; i <= len; ++i)
		s1[i + 1] = s2[i];
}
void sov()
{
	char s[105];
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	char tmps[105];
	int ans = 0;
	for(int i = 1; i <= len + 1; ++i)
	{
		for(char j = 'A'; j <= 'C'; ++j)
		{
			memset(tmps, 0, sizeof(tmps));
			copy(tmps, s, i, len, j);
//			printf("%d %c %s\n", i, j, tmps + 1);
			int tmp = calc(tmps, len + 1);
			ans = max(ans, tmp);
		}
	}
	printf("%d\n", ans);
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