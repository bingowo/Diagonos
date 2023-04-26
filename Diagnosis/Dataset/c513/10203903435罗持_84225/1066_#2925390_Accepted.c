#include <stdio.h>
#include <stdlib.h>
int cas,n,p,m,t;
int cnt = 0;
void dfs(int now,int end,int time){
	if(time==m){
		if(now==end) cnt++;
		return;
	}
	if(now==1) dfs(2,end,time+1);
	else if(now==n) dfs(n-1,end,time+1);
	else{
		dfs(now+1,end,time+1);
		dfs(now-1,end,time+1);
	}
}
int main(void)
{
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d %d %d %d",&n,&p,&m,&t);
		cnt = 0;
		dfs(p,t,0);
		printf("%lld\n",cnt);
	}
	return 0;
}