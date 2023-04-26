#include<stdio.h>
//c(n,k)*a^n*b^m
//(a×b) mod c=(a mod c * b mod c) mod c
//(a+b) mod c=(a mod c+ b mod c) mod c
static int ans[1001][1001];
int main()
{
	int T,cas,i,j,a,b,k,n,m;scanf("%d",&T);
	for(cas=0;cas<T;cas++)
	{
		scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);a%=10007;b%=10007;
		for(i=0;i<=n;i++)
		{
		    for(j=0;j<=m;j++)ans[i][j]=1;
		}
		for(i=0;i<=n;i++)//x的幂 
		{
			for(j=0;j<=m;j++)//y的幂 
			{
				if(a+b)
				{
					if(i==0)ans[i][j]=b*ans[i][j-1]%10007;
					else if(j==0)ans[i][j]=a*ans[i-1][j]%10007;
					else ans[i][j]=(a*ans[i-1][j]+b*ans[i][j-1])%10007;
				}
			}
		}
		printf("case #%d:\n%d\n",cas,ans[n][m]);
	}
	return 0;
}
