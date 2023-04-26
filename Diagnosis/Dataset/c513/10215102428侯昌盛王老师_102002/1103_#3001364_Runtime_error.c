#include <stdio.h>
#include <string.h>
int a=0;
int b=0;
void solve(char *s)
{
	int i;

	if(s[0]=='I'&&s[1]=='N') 
	{
		for(i=6;s[i]!='\0';i++)
		{
			if(a==0) a=a*10+s[i]-'0';
			else b=b*10+s[i]-'0';
		}
		return;
	}
	else if(s[0]=='M'&&s[1]=='U'&&s[2]=='L')
	{
		a=a*b;
		b=0;
	}
	else if(s[0]=='A'&&s[1]=='D'&&s[2]=='D')
	{
		a=a+b;
		b=0;
	}
	else if(s[0]=='D'&&s[1]=='I'&&s[2]=='V')
	{
		a/=b;
		b=0;
	}
	
	else if(s[0]=='O')
	{
		printf("%d\n",a);
	}
}
int main()
{
	char s[100];
	int a=0;
	int i=0;
	while(gets(s))
	{
		int len=strlen(s);
		int j=0;
		for(j;j<len;j++)
		{
			if(s[j]==',') s[j]=' ';
		}
		solve(s);
	
	}
	
	return 0;
}