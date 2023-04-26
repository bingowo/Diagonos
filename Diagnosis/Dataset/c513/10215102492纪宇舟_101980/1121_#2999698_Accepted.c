#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int n,maxm=0;
int w[11],a[1005];
int ABS(int x)
{
	if(x<0)return -x;return x;
}
void DFS(int x,int sum)
{
	if(x==n+1)return;
	for(int i=-1;i<=1;i++)
	{
		int s=sum+i*w[x];
		int d=ABS(s);
		if(d>maxm)maxm=d;
		a[d]=1;
		DFS(x+1,s);
	}
}
int main()
{
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	DFS(1,0);
	for(int i=1;i<=maxm;i++)printf("%d",a[i]);
	return 0;
}