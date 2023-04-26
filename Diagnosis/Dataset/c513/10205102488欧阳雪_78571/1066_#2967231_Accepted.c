#include<stdio.h>
int f(int all,int sta,int time,int end)
{
	if(time==0&&sta==end)
	{
		return 1;
	}
	if(time==0&&sta!=end)
	{
		return 0;
	}
	if(sta==1)
	{
		return f(all,sta+1,time-1,end);
	}
	if(sta==all){
		return f(all,sta-1,time-1,end);
	}
	return f(all,sta-1,time-1,end)+f(all,sta+1,time-1,end);
	
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int n,p,m,t;
		scanf("%d%d%d%d",&n,&p,&m,&t);
		printf("%d\n",f(n,p,m,t));
	}
 } 