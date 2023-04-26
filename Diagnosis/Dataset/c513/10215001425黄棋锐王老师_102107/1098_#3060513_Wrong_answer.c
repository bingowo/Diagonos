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
{ int k,T;
	scanf("%d",&T);
for(k=0;k<T;k++)
{	char s[200]={'\0'};
	int cnt[4]={0};
	char c[4]={0};
	scanf("%s",s);
	int l=strlen(s),i,t;
	for(i=0;i<l;i++)
	{	t=i%4;
		switch(t)
		{
			case 0:
			{
			if(s[i]=='!') cnt[0]++;
			else c[0]=s[i];
			break;
			}
			
			case 1:
			{if(s[i]=='!') cnt[1]++;
			else c[1]=s[i];
				break;
			}
			
			case 2:
			{if(s[i]=='!') cnt[2]++;
			else c[2]=s[i];
				break;
			}
			
			case 3:
			{if(s[i]=='!') cnt[3]++;
			 else c[3]=s[i];
				break;
			}
		}
	}
	int r=0,b=0,y=0,g=0;
	for(i=0;i<4;i++)
	{	if(c[i]=='R') r=i;
		if(c[i]=='B') b=i;
		if(c[i]=='Y') y=i;
		if(c[i]=='G') g=i;
	}
	printf("case #%d:\n",k);
	printf("%d ",cnt[r]);
	printf("%d ",cnt[b]);
	printf("%d ",cnt[y]);
	printf("%d\n",cnt[g]);
}
	return 0;
}