#include <stdio.h>
#include <string.h>

void solve(char *s,int *a)
{
	int i;

	if(s[0]=='I'&&s[1]=='N') 
	{
		a[s[3]]=0;
		if(s[6]!='-')
		{
			
			for(i=6;s[i]!='\0';i++)
			{
				a[s[3]]=a[s[3]]*10+s[i]-'0';
			}
			return;
		}
		else
		{
			for(i=7;s[i]!='\0';i++)
			{
				a[s[3]]=a[s[3]]*10+s[i]-'0';
				a[s[3]]=-a[s[3]];
			}
			return;
		}
	}
	else if(s[0]=='M'&&s[1]=='U'&&s[2]=='L')
	{
		a[s[4]]=a[s[4]]*a[s[7]];
	}
	else if(s[0]=='A'&&s[1]=='D'&&s[2]=='D')
	{
	a[s[4]]=a[s[4]]+a[s[7]];
	}
	else if(s[0]=='D'&&s[1]=='I'&&s[2]=='V')
	{
		a[s[4]]=a[s[4]]/a[s[7]];
	}
	else if(s[0]=='M'&&s[1]=='O')
	{
		a[s[4]]=a[s[7]];
	}
	else if(s[0]=='O')
	{
		printf("%d\n",a[s[4]]);
	}
}
int main()
{
	char s[100];
	int a[100]={0};
	int i=0;
	while(gets(s))
	{
		int len=strlen(s);
		int j=0;
		for(j;j<len;j++)
		{
			if(s[j]==',') s[j]=' ';
		}
		solve(s,a);
		//printf("aa=%d\n",a[66]);
		memset(s,'\0',sizeof(s));
	
	}
	
	return 0;
}