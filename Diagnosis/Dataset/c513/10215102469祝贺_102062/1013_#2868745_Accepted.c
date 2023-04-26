#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int t[3]={0,1,-1};
char s[100];int p=0;
long long a=0,b=0,c=1,d=1;

long long sim(long long a,long long b)
{
	a=a>0?a:-a;b=b>0?b:-b;
	long long c;
	while((c=a%b)!=0)
	{
		a=b;b=c;
	}
	return b;
}
int main()
{
	scanf("%s",s);
	while(s[p]!=0)
	{
		if(s[p]=='.')
			break;
		else
		{
			a=a*3+t[s[p]-'0'];
		}
		p++;
	}
	
	if(s[p++]=='.')
	{
		while(s[p]!=0)
		{
			b=b*3+t[s[p]-'0'];
			c*=3;
			p++;
		}
		d=sim(c,b);
	}
	
	if(!a && !b)printf("0");
	else if(a==0)printf("%lld %lld",b/d,c/d);
	else if(b==0)printf("%lld",a);
	else
	{
		if(b>0 && a>0)
			printf("%lld %lld %lld",a,b/d,c/d);
		else if(b<0 && a<0)
			printf("%lld %lld %lld",a,-b/d,c/d);
		else if(b<0 && a>0)
		{
			while(b<0 && a>0)
			{
				b+=c;a--;
			}
			if(a==0)
				printf("%lld %lld",b/d,c/d);
			else
				printf("%lld %lld %lld",a,b/d,c/d);
		}
		else
		{
			b-=c;a++;
			if(a==0)
				printf("%lld %lld",b/d,c/d);
			else
				printf("%lld %lld %lld",a,-b/d,c/d);				
		}
	}
	return 0;
}