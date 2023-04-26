#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int main()
{
	double sumal=0.0,sumar=0.0,suml=0.0,sumr=0.0;
	long long x=0,sig=1;
	char s[105],c;scanf("%s",s);
	int n=strlen(s),i;
	for(i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')x=x*10+s[i]-'0';
		if(s[i]>='a'&&s[i]<='z')
		{
			c=s[i];
			sumal+=x*sig;x=0;sig=1;
			continue;
		}
		if(s[i]<'0'||s[i]>'9')
		{
			suml+=x*sig;x=0;sig=1;
			if(s[i]=='-')sig=-1;
			if(s[i]=='=')break;
		}
	}
	for(i=i+1;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')x=x*10+s[i]-'0';
		if(s[i]>='a'&&s[i]<='z')
		{
			c=s[i];
			sumar+=x*sig;x=0;sig=1;
			continue;
		}
		if(s[i]<'0'||s[i]>'9'||i==n-1)
		{
			sumr+=x*sig;x=0;sig=1;
			if(s[i]=='-')sig=-1;
		}
	}
	sumal-=sumar;sumr-=suml;
	printf("%c=%.3f",c,sumr/sumal);
	return 0;
}