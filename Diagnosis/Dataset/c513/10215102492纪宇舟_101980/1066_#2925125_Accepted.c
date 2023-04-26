#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int n,p,m,t;
int ans;
void dfs(int pos,int time)
{
	if(time==m)
	{
		if(pos==t)++ans;
		return;
	}
	if(pos==1)dfs(pos+1,time+1);
	else if(pos==n)dfs(pos-1,time+1);
	else 
	{
		dfs(pos-1,time+1);dfs(pos+1,time+1);
	}
}
int main()
{
	int ct=0,T;scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%d%d%d%d",&n,&p,&m,&t);
		dfs(p,0);
		//printf("case #%d:\n",ct++);
		printf("%d\n",ans);
	}
	return 0;
}