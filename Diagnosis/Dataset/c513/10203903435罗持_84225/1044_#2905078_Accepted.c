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
	s[len++] = 'z';
	s[len] = '\0';
	int idx = 0,pos = 0;
	long long res = 0;
	while(pos<len)
	{
		while(pos+1<len && !(s[pos]=='0' && s[pos+1]=='x')) pos++;
		pos+=2;
		res = 0;
		while(pos<len)
		{
			//printf("%c  ",s[pos]);
			if(isdigit(s[pos])) res = res*16+s[pos]-'0';
			else if(s[pos]>='a' && s[pos]<='f') 
				res = res*16 + s[pos]-'a'+10;
			else 
			{
				if(s[pos-1]!='x')
				{
					printf("%lld ",res);
					have = 1;
				}
				pos++;
				break;
			}
			pos++;
		}
	}
	if(have==0) printf("-1");
	return 0;
 } 