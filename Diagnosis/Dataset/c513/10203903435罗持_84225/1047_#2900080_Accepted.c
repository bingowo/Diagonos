#include <stdio.h>
#include <string.h>
int T;
int main(void)
{
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++)
	{
		char s[600] = {0};
		scanf("%s",s);
		int len = strlen(s);
		int cnt[600] = {0};
		char res[600] = {0};
		int pos = 0;
		int lt=0,rt=1;
		while(rt<len)
		{
			if(rt-lt==255)
			{
				cnt[pos] = 255;
				res[pos] = s[lt];
				pos++;
				lt = rt;
				rt++;
			}
			else
			{
				if(s[rt]==s[rt-1]) rt++;
				else
				{
					cnt[pos] = rt-lt;
					res[pos] = s[lt];
					pos++;
					lt = rt;
					rt++;
				}
			}
		}
		cnt[pos] = rt-lt;
		res[pos] = s[lt];
		printf("case #%d:\n",kase);
		for(int i=0;i<=pos;i++) printf("%d%c",cnt[i],res[i]);
		putchar('\n');
	}
	return 0;
}