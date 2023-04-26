#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char s[1000010] = {0}; 
int cnt[300] = {0};
int main(void)
{
	scanf("%s",s);
	int len = strlen(s);
	int lt = 0,rt = 1;
	int resl=0,resr=1,maxlen=1;
	cnt[s[0]] = 1;
	while(rt<len)
	{
		if(cnt[s[rt]]==0)
		{
			cnt[s[rt]]++;
			rt++;
		}
		else
		{
			if(maxlen<rt-lt)
			{
				maxlen = rt-lt;
				resl = lt;
				resr = rt;
			}
			cnt[s[lt]]--;
			lt++;
		}
	}
	if(maxlen<rt-lt)
	{
		maxlen = rt-lt;
		resl = lt;
		resr = rt;
	}
	for(int i=resl;i<resr;i++) printf("%c",s[i]);
	return 0;
}