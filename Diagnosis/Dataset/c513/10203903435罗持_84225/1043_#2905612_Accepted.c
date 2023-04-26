#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int T;
char s[111]= {0};
int cal(int pos,char c)
{
	int res = 0;
	char t[111];
	strcpy(t,s);
	for(int i=strlen(t)-1;i>=pos;i--) t[i+1] = t[i];
	t[pos] = c;
	char lf[111] = {0};
	int idx = 0;
	while(1)
	{
		int flag = 1;
		for(int i=1;i<strlen(t);i++)
		{
			if(t[i]==t[i-1])
			{
				flag = 0;
				break;
			}
		}
		if(flag) break;
		if(t[0]!=t[1]) lf[idx++] = t[0];
		for(int i=1;i+1<strlen(t);i++)
			if(t[i]!=t[i-1] && t[i]!=t[i+1]) lf[idx++] = t[i];
		if(t[strlen(t)-1]!=t[strlen(t)-2]) lf[idx++] = t[strlen(t)-1];
		res += strlen(t)-idx;
		lf[idx] = '\0';
		memset(t,0,sizeof(t));
		strcpy(t,lf);
		memset(lf,0,sizeof(lf));
		idx = 0;
	}
	return res;
}
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
int main(void)
{
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++)
	{
		int res = 0;
		scanf("%s",s);
		int len = strlen(s);
		for(int i=0;i<=len;i++)
		{
			int a1 = cal(i,'A');
			int a2 = cal(i,'B');
			int a3 = cal(i,'C'); 
			res = max(max(max(a1,a2),a3),res);
		}
		printf("case #%d:\n",kase);
		printf("%d\n",res);
	}
	return 0;
} 