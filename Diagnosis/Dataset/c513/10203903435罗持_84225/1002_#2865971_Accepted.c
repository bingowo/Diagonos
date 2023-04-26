#include <stdio.h>
#include <string.h>
int T;
int main(void)
{
	scanf("%d",&T);
	int kase;
	for(kase=0;kase<T;kase++)
	{
		int table[300];
		char s[100];
		scanf("%s",s);
		long long res = 0;
		int len = strlen(s);
		int i;
		int cnt = 0;
		memset(table,-1,sizeof(table));
		for(i=0;i<len;i++)
		{
			if(table[s[i]]==-1)
			{
				if(cnt==0) table[s[i]] = 1;
				else if(cnt==1) table[s[i]] = 0;
				else table[s[i]] = cnt;
				cnt++;
			}
		}
		if(cnt==1) cnt = 2;
		for(i=0;i<len;i++)
			res = res*cnt + table[s[i]];
		printf("case #%d:\n",kase);
		printf("%lld\n",res);
	}
	return 0;
}