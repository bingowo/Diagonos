#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int a[11][11],sum[11][11];
int main()
{
	int n,m,c,k;int x,y;
	int T,ct=0;scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(sum,0,sizeof(sum));
		scanf("%d%d%d%d",&n,&m,&c,&k);
		while(c--)
		{
			scanf("%d%d",&x,&y);
			a[x][y]=1;
		}
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
		int ans=0;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		for(int p=i;p<=n;p++)
		for(int d=j;d<=m;d++)
		if(sum[p][d]-sum[i-1][d]-sum[p][j-1]+sum[i-1][j-1]>=k)++ans;
		printf("case #%d:\n",ct++);printf("%d\n",ans);
	}
	return 0;
}