#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char s[111] = {0};
int main(void)
{
	scanf("%s",s);
	int res = 0;
	int len = strlen(s);
	char t[111] = {0};
	int idx = 0;
	int pos = 0;
	while(pos<len)
	{
		if(isdigit(s[pos]))
		{
			t[idx++] = s[pos];
		}
		else
		{
			int flag = 1;
			for(int i=0;i<idx;i++)
			{
				if(t[i]=='0')
				{
					if(flag);
				}
				else
				{
					flag = 0;
					if(idx-i>res) res = idx-i;
				}
			}
			idx = 0;
			memset(t,0,sizeof(t));
		}
		pos++;
	}
	int flag = 1;
	for(int i=0;i<idx;i++)
	{
		if(t[i]=='0')
		{
			if(flag);
		}
		else
		{
			flag = 0;
			if(idx-i>res) res = idx-i;
		}
	}
	printf("%d",res);
	return 0;
}