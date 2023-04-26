#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 1000000007


long long num(char*s,int x)//x位置上的可能数 
{  int i,l=strlen(s);
	long long t;
	if(x==0)
	{  if(s[0]==s[1]) t=1;
		else  return t=2;
	}
	
	else if(l-1==x)
	{	if(s[x]==s[x-1]) t= 1;
		else  t=2;
	}
	
	else 
	{ if(s[x]==s[x-1]&&s[x]==s[x+1]) t=1;//aaa
		else if(s[x]==s[x-1]&&s[x]!=s[x+1]) t=2;//aab
		else if(s[x]!=s[x-1]&&s[x]==s[x+1]) t=2;//abb
		else if(s[x]!=s[x-1]&&s[x]!=s[x+1]&&s[x-1]==s[x+1]) t=2;//aba
		else if (s[x]!=s[x-1]&&s[x]!=s[x+1]&&s[x-1]!=s[x+1]) t=3;//abc
	}
	return t;
}
int main() 
{ char s[2000]={'\0'};
	scanf("%s",s);
	int i,l=strlen(s);
	long long ANS=1;
	if(l==1) printf("1");
	else 
	{
	for(i=0;i<l;i++)
	{
		ANS=(ANS%max)*(num(s,i)%max)%max;
	}
	 printf("%lld",ANS);
	}
	return 0;
}