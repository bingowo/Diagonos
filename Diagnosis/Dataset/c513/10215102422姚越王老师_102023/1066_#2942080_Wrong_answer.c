#include<stdio.h>
#include<math.h>
typedef unsigned long long ull;
ull f(int n,int p,int m,int t)//共n幢楼，开始在p楼，过m分钟到t楼 
{
	if(abs(t-p)>m)return 0;
	else if(abs(t-p)==m)return 1;
	else
	{
		if(t==1)return f(n,p,m-1,t+1);
		else if(t==n)return f(n,p,m-1,t-1);
		else return f(n,p,m-1,t+1)+f(n,p,m-1,t-1);
	}
}
int main()
{
	int T,n,p,m,t;scanf("%d",&T);
	for(int cas=0;cas<T;cas++)
	{
		scanf("%d %d %d %d",&n,&p,&m,&t);
		printf("%llu\n",f(n,p,m,t));
	}
	return 0;
}