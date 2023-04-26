#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long long int f(int a,int b,int n,int m)
{
	static long long int x[1000][1000]={1},i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i!=0||j!=0)
			{
				if(i==0)
				{
					x[i][j]=b*x[i][j-1]%10007;
				}
				else if(j==0)
				{
					x[i][j]=a*x[i-1][j]%10007;
				}
				else
				{
					x[i][j]=(a*x[i-1][j]+b*x[i][j-1])%10007;
				}	
			}
		}
	}
	return x[n][m];
}

int main()
{
	int t,a,b,k,n,m;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
		printf("case #%d:\n",i);
		printf("%lld\n",f(a,b,n,m));
	}
	
}