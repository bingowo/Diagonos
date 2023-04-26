#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int T;
int cnt[26] = {0};
int main(void)
{
	scanf("%d",&T);
	getchar();
	for(int kase=0;kase<T;kase++)
	{
		memset(cnt,0,sizeof(cnt));
		char s[300];
		gets(s);
		int n = strlen(s);
		for(int i=0;i<n;i++)
			if(isalpha(s[i])) 
			{
				cnt[s[i]-'A']++;
			}
		printf("case #%d:\n",kase);
		int idx = 0;
		for(int i=0;i<n;i++)
		{
			if(isalpha(s[i]))
			{
				while(cnt[idx]==0) idx++;
				printf("%c",'A'+idx);
				cnt[idx]--;
			}
			else printf("%c",s[i]);
		}
		putchar('\n');
	}
	return 0;
}