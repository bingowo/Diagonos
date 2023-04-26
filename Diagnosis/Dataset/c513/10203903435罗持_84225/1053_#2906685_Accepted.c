#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
const int MOD = 65536;
const char HEAD[] = "$GPRMC,";
char buf[1000010] = {0};
char s[1000010];
int cal(char c)
{
	if(isdigit(c)) return c-'0';
	else return c-'A'+10;
}
int check(char buf[])
{
	int len = strlen(buf);
	int pos = 13;
	if(13>=len){
		return 0;
	}
	while(pos < len && !isalpha(buf[pos])) pos++;
	if(buf[pos]!='A'){
		return 0;
	} 
	int code = 0;
	int i;
	for(i=1;i<len&&buf[i]!='*';i++)
		code = (code^buf[i])%MOD;
	int id = 0;
	i++;
	for(;i<len;i++)
		id = id*16 + cal(buf[i]);
	if(id==code) return 1;
	else{
		return 0;
	}
}
int main(void)
{
	while(scanf("%s",buf)!=EOF)
	{
		if(strcmp("END",buf)==0) break;
		int flag = 1;
		int i;
		for(i=0;i<7;i++)
		{
			if(buf[i]!=HEAD[i])
			{
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			if(check(buf))
			{
				strcpy(s,buf);
			}
		}
	}
	int hour = 0,min = 0,sec = 0;
	hour = 10*(s[7]-'0') + (s[8]-'0');
	min = 10*(s[9]-'0') + (s[10]-'0');
	sec = 10*(s[11]-'0') + (s[12]-'0');
	hour = (hour+8)%24;
	printf("%02d:%02d:%02d",hour,min,sec);
	return 0;
}