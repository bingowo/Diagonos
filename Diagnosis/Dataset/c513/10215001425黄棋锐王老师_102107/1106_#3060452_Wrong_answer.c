#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 1000000007


int num(char*s,int x)//x位置上的可能数 
{  int i,l=strlen(s);
	if(x==0)
	{  if(s[0]==s[1]) return 1;
		else  return 2;
	}
	
	else if(l-1==x)
	{	if(s[x]==s[x-1]) return 1;
		else  return 2;
	}
	
	else 
	{ if(s[x]==s[x-1]&&s[x]==s[x+1]) return 1;//aaa
		else if(s[x]==s[x-1]&&s[x]!=s[x+1])return 2;//aab
		else if(s[x]!=s[x-1]&&s[x]==s[x+1]) return 2;//abb
		else if(s[x]!=s[x-1]&&s[x]!=s[x+1]&&s[x-1]==s[x+1]) return 2;//aba
		else if (s[x]!=s[x-1]&&s[x]!=s[x+1]&&s[x-1]!=s[x+1]) return 3;//abc
	}
}
int main() 
{ char s[2000]={'\0'};
	scanf("%s",s);
	int i,l=strlen(s);
	int ANS=1;
	if(l==1) printf("1");
	else 
	{
	for(i=0;i<l;i++)
	{
		ANS=(ANS%max)*(num(s,i)%max)%max;
	}
	 printf("%d",ANS);
	}
	return 0;
}