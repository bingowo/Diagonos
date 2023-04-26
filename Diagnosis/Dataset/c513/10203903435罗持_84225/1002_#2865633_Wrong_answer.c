#include <stdio.h>
#include <string.h>
int T;
int main(void)
{
	scanf("%d",&T);
	int kase;
	for(kase=0;kase<T;kase++)
	{
		int table[300] = {0};
		int vis[300] = {0};
		char s[100] = {0};
		scanf("%s",s);
		long long res = 0;
		int len = strlen(s);
		int cnt = 0;
		int i;
		for(i=0;i<len;i++)
		{
			if(!vis[s[i]])
			{
				vis[s[i]] = 1;
				cnt++;
				if(cnt==1) table[s[i]] = 1;
				else if(cnt==2) table[s[i]] = 0;
				else table[s[i]] = cnt-1;
			}
		}
		printf("%d\n",cnt);
		long long weigh = 1;
		for(i=len-1;i>=0;i--)
		{
			res += weigh * table[s[i]];
			weigh *= cnt;
		}
		printf("case #%d:\n",kase);
		printf("%lld\n",res);
	}
	return 0;
}