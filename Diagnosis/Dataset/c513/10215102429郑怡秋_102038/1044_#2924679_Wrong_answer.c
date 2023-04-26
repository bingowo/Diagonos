#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
int res(char c)
{
	if(isdigit(c)) return c-'0';
	else if(c>='a'&&c<='f') return c-'a'+10;
	else return -1;
}
int main()
{
	char s[100001];
	scanf("%s",s);
	int i=0;
	int l=strlen(s);
	int mark=0;
	while(i<l)
	{   //printf("%c\n",s[i+2]);
		if(s[i]=='0'&&i+2<l&&s[i+1]=='x'&&(res(s[i+2])!=-1))
		{	
			i+=2;mark+=1;
			
			unsigned int ans=res(s[i]);i++;
			while((s[i]!='0'||s[i+1]!='x')&&i<l&&(res(s[i])!=-1))
			{
				ans=(ans*16+res(s[i]));i++;
			}
			printf("%u ",ans);
		}
		else if(s[i]=='0'&&i+2<l&&s[i+1]=='x'&&(res(s[i+2])==-1))
		{
			printf("-1 ");
			mark++;
			i++;
		}
		else i++;	
	}
	if(mark==0) printf("-1");
	return 0;
}