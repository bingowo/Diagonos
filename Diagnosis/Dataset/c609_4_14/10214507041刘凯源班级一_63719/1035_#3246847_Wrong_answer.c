#include<stdio.h>
#include<string.h>
void sov()
{
	char s[105];
	scanf("%s", s + 1);
	int len = strlen(s + 1);
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
	if(tot >= 4)
		ans += 4;
	else if(tot == 0)
		ans += 1;
	else
		ans += 2;
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