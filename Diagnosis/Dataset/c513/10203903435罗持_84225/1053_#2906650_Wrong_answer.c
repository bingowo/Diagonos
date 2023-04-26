#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
const int MOD = 65536;
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
		//printf("111\n");
		return 0;
	}
	while(pos < len && !isalpha(buf[pos])) pos++;
	if(buf[pos]!='A'){
		//printf("222\n");
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
	//printf("%d %d\n",code,id);
	if(id==code) return 1;
	else{
		//printf("333\n");
		return 0;
	}
}
int main(void)
{
	while(scanf("%s",buf)!=EOF)
	{
		if(strcmp("END",buf)==0) break;
		char head[10];
		strncpy(head,buf,7);
		if(strcmp("$GPRMC,",head)==0)
		{
			//printf("here\n");
			if(check(buf))
			{
				//printf("again\n");
				//memset(s,0,sizeof(s));
				strcpy(s,buf);
			}
		}
	}
    printf("%s\n",s);
	int hour = 0,min = 0,sec = 0;
	hour = 10*(s[7]-'0') + (s[8]-'0');
	min = 10*(s[9]-'0') + (s[10]-'0');
	sec = 10*(s[11]-'0') + (s[12]-'0');
	//printf("%d %d %d\n",hour,min,sec);
	hour = (hour+8)%24;
	printf("%02d:%02d:%02d",hour,min,sec);
	return 0;
}