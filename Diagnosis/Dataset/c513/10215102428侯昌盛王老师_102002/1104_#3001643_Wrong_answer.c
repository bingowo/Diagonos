#include <stdio.h>
#include <string.h>

void solve(char *s,int *a)
{
	int i;
	int len=strlen(s);
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
				
			}
			a[s[3]]=0-a[s[3]];
			return;
		}
	}
	else if(s[0]=='M'&&s[1]=='U'&&s[2]=='L')
	{
		if(len==9) a[s[4]]=a[s[4]]*a[s[7]];
		else a[s[4]]=a[s[7]]*a[s[10]];
	}
	else if(s[0]=='A'&&s[1]=='D'&&s[2]=='D')
	{
		if(len==9) a[s[4]]=a[s[4]]+a[s[7]];
		else a[s[4]]=a[s[7]]+a[s[10]];
	}
	else if(s[0]=='D'&&s[1]=='I'&&s[2]=='V')
	{
		if(len==9) a[s[4]]=a[s[4]]/a[s[7]];
		else a[s[4]]=a[s[7]]/a[s[10]];
	}
	else if(s[0]=='M'&&s[1]=='O'&&s[2]=='V')
	{
		a[s[4]]=a[s[7]];
		
	}
	else if(s[0]=='S')
	{
		if(len==9) a[s[4]]=a[s[4]]-a[s[7]];
		else a[s[4]]=a[s[7]]-a[s[10]];
		
	}
	else if(s[0]=='O'&&s[1]=='R')
	{
		if(len==9) a[s[3]]=a[s[3]]|a[s[6]];
		else a[s[3]]=a[s[6]]|a[s[9]];
	}
	else if(s[0]=='X'&&s[1]=='O')
	{
		if(len==9) a[s[4]]=a[s[4]]^a[s[7]];
		else a[s[4]]=a[s[7]]^a[s[10]];
	}
	else if(s[0]=='M'&&s[1]=='O'&&s[2]=='D')
	{
		if(len==9) a[s[4]]=a[s[4]]%a[s[7]];
		else a[s[4]]=a[s[7]]%a[s[10]];
	}
	else if(s[0]=='A'&&s[1]=='N'&&s[2]=='D')
	{
		if(len==9) a[s[4]]=a[s[4]]&a[s[7]];
		else a[s[4]]=a[s[7]]+a[s[10]];
	}
	else if(s[0]=='X'&&s[1]=='C')
	{
		int res;
		res=a[s[5]];
		a[s[5]]=a[s[8]];
		a[s[8]]=res;
	}
	else if(s[0]=='O'&&s[1]=='U')
	{
		printf("%lld\n",a[s[4]]);
	}
}
int main()
{
	char s[1000];
	long long int a[100]={0};
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
		//printf("aa=%d\n",a[68]);
		memset(s,'\0',sizeof(s));
	
	}
	
	return 0;
}