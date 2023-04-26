#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int T;
void dfs(int now,int n,char t[],char have[],int len)
{
	if(now==n) return;
	for(int i=now;i<n;i++)
	{
		t[len] = have[i];
		t[len+1] = '\0';
		printf("%s\n",t);
		dfs(i+1,n,t,have,len+1);
		t[len] = '\0';
	}
}
int main(void)
{
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++)
	{
		char s[20];
		scanf("%s",s);
		int cnt[300] = {0};
		int len = strlen(s);
		char have[30] = {0};
		int idx = 0;
		for(int i=0;i<len;i++)
			cnt[s[i]] = 1;
		for(int i=0;i<300;i++)
			if(cnt[i]) have[idx++] = (char)i;
		char t[30] = {0};
		printf("case #%d:\n",kase);
		dfs(0,idx,t,have,0);
	}
	return 0;
}