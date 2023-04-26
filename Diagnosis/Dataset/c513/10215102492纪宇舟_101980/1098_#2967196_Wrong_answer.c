#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
char s[105];
int n,k[4],ans[4];
void solve(int pos)
{
	//printf("%d\n",pos);
	if(pos-3>=0&&s[pos-1]!='!'&&s[pos-2]!='!'&&s[pos-3]!='!')
	{
		k[0]=k[1]=k[2]=k[3]=1;
		for(int i=1;i<=3;i++)
		{
			if(s[pos-i]=='R')k[0]=0;
			else if(s[pos-i]=='B')k[1]=0;
			else if(s[pos-i]=='Y')k[2]=0;
			else if(s[pos-i]=='G')k[3]=0;
		}
		if(k[0]==1)
		{
			ans[0]++;s[pos]='R';
		}
		else if(k[1]==1)
		{
			ans[1]++;s[pos]='B';
		}
		else if(k[2]==1)
		{
			ans[2]++;s[pos]='Y';
		}
		else if(k[3]==1)
		{
			ans[3]++;s[pos]='G';
		}
	}
	if(pos+3<n&&s[pos+1]!='!'&&s[pos+2]!='!'&&s[pos+3]!='!')
	{
		k[0]=k[1]=k[2]=k[3]=1;
		for(int i=1;i<=3;i++)
		{
			if(s[pos+i]=='R')k[0]=0;
			else if(s[pos+i]=='B')k[1]=0;
			else if(s[pos+i]=='Y')k[2]=0;
			else if(s[pos+i]=='G')k[3]=0;
		}
		if(k[0]==1)
		{
			ans[0]++;s[pos]='R';
		}
		else if(k[1]==1)
		{
			ans[1]++;s[pos]='B';
		}
		else if(k[2]==1)
		{
			ans[2]++;s[pos]='Y';
		}
		else if(k[3]==1)
		{
			ans[3]++;s[pos]='G';
		}
	}
}
int main()
{
	int ct=0,T;scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);n=strlen(s);
		ans[0]=ans[1]=ans[2]=ans[3]=0;
		while(1)
		{
			int sig=0;
			for(int i=0;i<n;i++)
			{
				if(s[i]=='!')
				{
					sig=1;solve(i);
				}
			}
			if(sig==0)break;
		}
		printf("case #%d:\n",ct++);
		printf("%d %d %d %d\n",ans[0],ans[1],ans[2],ans[3]);
	}
	return 0;
}