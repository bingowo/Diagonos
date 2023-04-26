#include <stdio.h>
#include <string.h>
int T;
int main(void)
{
	scanf("%d",&T);
	int kase;
	for(kase=0;kase<T;kase++)
	{
		int table[300] = {-1};
		int vis[300] = {0};
		char s[100] = {0};
		scanf("%s",s);
		long long res = 0;
		int len = strlen(s);
		int i;
		int cnt = 0;
		for(i=0;i<len;i++)
		{
			if(!vis[s[i]])
			{
				vis[s[i]] = 1;
				cnt++;
			}
		}
		memset(vis,0,sizeof(vis));
		int num = 0;
		for(i=0;i<len;i++)
		{
			if(!vis[s[i]])
			{
				vis[s[i]] = 1;
				if(num == 0) table[s[i]] = 1;
				else if(num == 1) table[s[i]] = 0;
				else table[s[i]] = num;
				num++;
			}
		}
		for(i=0;i<len;i++)
		{
			res = res*cnt + table[s[i]];
		}
		printf("case #%d:\n",kase);
		printf("%lld\n",res);
	}
	return 0;
}