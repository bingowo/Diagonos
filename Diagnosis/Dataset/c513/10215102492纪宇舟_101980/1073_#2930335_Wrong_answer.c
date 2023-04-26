#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
#define mod 10007
typedef long long LL;
int n;
int num[20];
LL dp[20][10];
int MIN(int x,int y)
{
	if(x<y)return x;
	return y;
}
LL DP(int pos,int x,int lim,int sum)
{
	if(pos==-1)
	{
		if(sum%9)return 1;
		return 0;
	}
	if(!lim&&dp[pos][x]!=-1)return dp[pos][x];
	int a;
	if(lim)a=num[pos];
	else a=8;
	LL tol=0;
	for(int i=0;i<=a;i++)
	{
		//if(i==9)continue;
		tol+=DP(pos-1,i,lim&&num[pos]==i,sum+i);
	}
	dp[pos][x]=tol;
	return tol;
}
LL CAL(LL x)
{
	/*while(x)
	{
		num[++n]=x%10;x/=10;
	}*/
	for(int i=0;i<=18;i++)
	{
		num[i]=x%10;x/=10;
	}
	memset(dp,-1,sizeof(dp));
	return DP(18,0,1,0);
}
int main()
{
	LL a,b;
	scanf("%lld%lld",&a,&b);
	printf("%lld",CAL(b)-CAL(a-1));
	return 0;
}