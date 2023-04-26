#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char s[100010] = {0};
char t[100010] = {0};
int main(void)
{
	int have = 0;
	scanf("%s",s);
	int len = strlen(s);
	int idx = 0,pos = 0;
	while(pos+1<len)
	{
		if(s[pos]=='0' && s[pos+1]=='x')
		{
			if(idx!=0)
			{
				t[idx] = '\0';
				long long res = 0;
				for(int i=0;i<idx;i++)
				{
					if(isdigit(t[i])) res = res*16+t[i]-'0';
					else if(t[i]>='a' && t[i]<='f') 
						res = res*16 + t[i]-'a'+10;
					else break;
				}
				printf("%lld ",res);
				have = 1;
			}
			memset(t,0,sizeof(t));
			idx = 0;
			pos += 2;
		}
		else
		{
			t[idx++] = s[pos++];
		}
	}
	if(s[0]=='0' && s[1]=='x')
	{
		if(pos==len-1) t[idx++] = s[pos++];
		t[idx] = '\0';
		long long res = 0;
		for(int i=0;i<idx;i++)
		{
			if(isdigit(t[i])) res = res*16+t[i]-'0';
			else if(t[i]>='a' && t[i]<='f') 
				res = res*16 + t[i]-'a'+10;
			else break;
		}
		printf("%lld ",res);
		have = 1;
	}
	if(have==0) printf("-1");
	return 0;
 }