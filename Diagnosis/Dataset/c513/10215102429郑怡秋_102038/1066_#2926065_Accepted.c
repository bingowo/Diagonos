#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
int f(int n,int p,int m,int t)
{
	if(m==0&&p==t) return 1;
	else if(m==0&&p!=t) return 0;
	else if(p==1) return f(n,p+1,m-1,t);
	else if(p==n) return f(n,p-1,m-1,t);
	else return f(n,p-1,m-1,t)+f(n,p+1,m-1,t);
}
int main()
{
	int cas;
	scanf("%d",&cas);
	for(int i=0;i<cas;i++)
	{
		long long n,p,m,t;
		scanf("%d%d%d%d",&n,&p,&m,&t);
		int ans=f(n,p,m,t);
		printf("%d\n",ans);
	}
}