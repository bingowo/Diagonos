#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
char s[100001];
int main()
{
	scanf("%s",s);
	int n=strlen(s);
	int sig=0,out=0;
	long long ans=-1;
	for(int i=0;i<n;i++)
	{
		if(sig)
		{
			if((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<=(5+'a')))
			{
				if(ans==-1)ans=0;
				if(s[i]>='0'&&s[i]<='9')ans=ans*16+s[i]-'0';
				else ans=ans*16+s[i]-'a'+10;
			}
			else
			{
				sig=0;
				if(ans!=-1)
				{
					printf("%lld ",ans);
					ans=-1;out=1;
				}
			}
		}
		if(s[i]=='0'&&s[i+1]=='x')
		{
			sig=1;i+=1;
		}
	}
	if(ans!=-1)
	{
		printf("%lld",ans);out=1;
	}
	if(out==0)printf("-1");
	return 0;
}