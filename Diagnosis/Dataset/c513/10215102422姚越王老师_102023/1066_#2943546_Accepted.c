#include<stdio.h>
#include<math.h>
typedef unsigned long long ull;
int main()
{
	int T,n,p,m,t,i,j;scanf("%d",&T);
	for(int cas=0;cas<T;cas++)
	{
		scanf("%d %d %d %d",&n,&p,&m,&t);
		int a[m+1][n];//第一维是时间，第二位是楼号
		for(i=0;i<=m;i++)
		{
			for(j=0;j<n;j++)
				a[i][j]=0;
		}
		a[0][p-1]=1;
		for(i=1;i<=m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(j==0)a[i][j]=a[i-1][1];
				else if(j==n-1)a[i][j]=a[i-1][n-2];
				else a[i][j]=a[i-1][j-1]+a[i-1][j+1];
			}
		}
		printf("%d\n",a[m][t-1]);
	}
	return 0;
}