#include <stdio.h>
#include <string.h>
#include <ctype.h>
int T;
char table[6][10] = {"the","a","an","of","for","and"};
int main(void)
{
	scanf("%d",&T);
	getchar();
	for(int kase=0;kase<T;kase++)
	{
		char s[200] = {0};
		int res = 0;
		gets(s);
		int len = strlen(s);
		for(int i=0;i<len;i++)
			if(s[i]>='A' && s[i]<='Z') s[i] = s[i]+'a'-'A';
		int lt = 0,rt = 0;
		char t[50] = {0};
		int pos = 0;
		while(rt<len)
		{
			if(s[rt]!=' ')
			{
				t[pos] = s[rt];
				pos++;
				rt++;
			}
			else
			{
				int flag = 1;
				t[pos] = '\0';
				for(int i=0;i<6;i++)
				{
					if(strcmp(table[i],t)==0)
					{
						flag = 0;
						break;
					} 
				}
				if(flag) res++;
				lt = rt+1;
				rt = lt;
				memset(t,0,sizeof(t));
				pos = 0;
			}
		}
		int flag = 1;
		t[pos] = '\0';
		for(int i=0;i<6;i++)
		{
			if(strcmp(table[i],t)==0)
			{
				flag = 0;
				break;
			} 
		}
		if(flag) res++;
		lt = rt+1;
		rt = lt;
		memset(t,0,sizeof(t));
		pos = 0;
		printf("case #%d:\n",kase);
		printf("%d\n",res);
	}
	return 0;
}