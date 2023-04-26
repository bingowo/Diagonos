#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
#define M 10007
int pingf(int a,int n)
{
	int ans=1;
	a%=M;
	while(n>0)
	{
		if(n&1==1)
		{
			ans*=a;ans%=M;
		}
		a=a*a;
		a%=M;
		n>>=1;
	}
	return ans;
}
int mood(int n,int k)//c,n,k 
{
	
	int ans=0;
	int p[1000];
	p[0]=1;
	for(int i=1;i<=n;i++)
	{
		p[i]=p[i-1]*i%M;
	}
	ans=p[n]*pingf((p[k]*p[n-k]%M),M-2)%M;
	return ans;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int a,b,k,n,m;
		scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
		printf("case #%d:\n",i);
		int nn=n;
		if(n>m) nn=m;
		long long ans;
		ans=pingf(a,n);
		ans=(ans*pingf(b,m))%M;
		ans=(ans*mood(k,n))%M;
		printf("%lld\n",ans);
	}
	return 0;
}