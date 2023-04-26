#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int cas,cnt,n,m,p,t;
void dfs(int cur,int time)
{
	if(time==0)
	{
		if(cur==t)
		{
			cnt++;
			return ;
		}
		else
			return ;
	}
	else
	{
		if(cur==1)
		{
			dfs(2,time-1);
		}
		else if(cur==n)
		{
			dfs(n-1,time-1);
		}
		else
		{
			dfs(cur-1,time-1);
			dfs(cur+1,time-1);
		}
		}
}
int main()
{
	scanf("%d",&cas);
	while(cas--)
	{
		cnt=0;
		scanf("%d%d%d%d",&n,&p,&m,&t);
		dfs(p,m);
		printf("%d\n",cnt);
	 } 
	return 0;
 } 