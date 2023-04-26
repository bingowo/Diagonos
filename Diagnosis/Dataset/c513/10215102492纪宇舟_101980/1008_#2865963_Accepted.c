#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
int a[21],b[21];
int cmp(int x,int y)
{
	int cnt1=0,cnt2=0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	do
	{
		a[++cnt1]=x%2;x/=2;
	}while(x);
	do
	{
		b[++cnt2]=y%2;y/=2;
	}while(y);
	int ans=0,i,j;
	for(int i=1;i<21;i++)
	if(a[i]!=b[i])++ans;
	return ans;
}
int main()
{   
	int T;scanf("%d",&T);
	while(T--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",cmp(x,y));
	}
	return 0;
}