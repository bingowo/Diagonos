#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int T;
int main(void)
{
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++)
	{
		char s[30],res[30];
		scanf("%s",s);
		int len = strlen(s);
		int cnt[30] = {0};
		int have[15] = {0};
		for(int i=0;i<len;i++) cnt[s[i]-'A']++;
		have[0] = cnt['Z'-'A'];
		have[1] = cnt['O'-'A']-cnt['Z'-'A']-cnt['W'-'A']-cnt['U'-'A'];
		have[2] = cnt['W'-'A'];
		have[3] = cnt['H'-'A']-cnt['G'-'A'];
		have[4] = cnt['U'-'A'];
		have[5] = cnt['F'-'A']-cnt['U'-'A'];
		have[6] = cnt['X'-'A'];
		have[7] = cnt['S'-'A']-cnt['X'-'A'];
		have[8] = cnt['G'-'A'];
		have[9] = cnt['I'-'A']-cnt['X'-'A']-(cnt['F'-'A']-cnt['U'-'A'])-cnt['G'-'A'];
		int idx = 0;
		for(int i=0;i<=9;i++)
			for(int j=0;j<have[i];j++) res[idx++] = i+'0';
		res[idx] = '\0';
		printf("case #%d:\n",kase);
		printf("%s\n",res);
	}
	return 0;
}