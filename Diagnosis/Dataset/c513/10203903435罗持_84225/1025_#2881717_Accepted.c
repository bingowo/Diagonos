#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cal(char *s)
{
	int len = strlen(s);
	int table[30] = {0};
	for(int i=0;i<len;i++) table[s[i]-'A']++;
	int cnt = 0;
	for(int i=0;i<26;i++)
	{
		if(table[i]!=0) cnt++;
	}
	return cnt;
}
int mycmp(const void*a,const void*b)
{
	char *aa = *(char**)a;
	char *bb = *(char**)b;
	int na = cal(aa);
	int nb = cal(bb);
	if(na==nb) return strcmp(aa,bb);
	return nb-na;
}
int main(void)
{
	char *s[111];
	int T;
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++)
	{
		int n;
		scanf("%d",&n);
		char ss[30];
		for(int i=1;i<=n;i++)
		{
			scanf("%s",ss);
			strcpy(s[i]=(char*)malloc((strlen(ss)+5)*sizeof(char)),ss);
		}
		qsort(s+1,n,sizeof(s[0]),mycmp);
		printf("case #%d:\n",kase);
		for(int i=1;i<=n;i++) printf("%s\n",s[i]);
	}
	return 0;
}