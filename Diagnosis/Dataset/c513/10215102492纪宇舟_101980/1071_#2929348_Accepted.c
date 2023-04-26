#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
#define mod 10007
typedef long long LL;
LL tol[1005];
LL POW(LL x,int n)
{
	if(n==0)return 1;
	if(n==1)return x;
	LL s=POW(x,n/2);
	if(n&1)return (s*s)%mod*x%mod;
	return (s*s)%mod;
}
LL C(LL n,LL m)
{
	LL up=1,down=1;
	for(int i=n-m+1;i<=n;i++)up=up*i%mod;
	for(int i=2;i<=m;i++)down=down*i%mod;
	return up*POW(down,mod-2)%mod;//Çó·ÖÄ¸¹ØÓÚmodµÄÄæÔª 
}
int main()
{
	int a,b,k,n,m;
	int ct=0,T;scanf("%d",&T);
	memset(tol,0,sizeof(tol));
	while(T--)
	{
		scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
		printf("case #%d:\n",ct++);
		LL ans=(POW(a,n)%mod)*(POW(b,m)%mod)*C(k,n)%mod;
		printf("%lld\n",ans);
	}
	return 0;
}