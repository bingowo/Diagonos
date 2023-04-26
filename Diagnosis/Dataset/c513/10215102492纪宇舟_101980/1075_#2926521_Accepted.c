#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int path[205][205];
void printpath(int n,int m)
{
	if(n==1&&m==1)return;
	if(path[n][m]==0)
	{
		printpath(n-1,m);
		printf("D");
	}
	else
	{
		printpath(n,m-1);
		printf("R");
	}
}
int main()
{
	int a[205][205],f[205][205];
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(i==1)
		{
			f[i][j]=f[i][j-1]+a[i][j];
			path[i][j]=1;
		}
		else if(j==1)
		{
			f[i][j]=f[i-1][j]+a[i][j];
			path[i][j]=0;
		}
		else if(f[i-1][j]<f[i][j-1])
		{
			f[i][j]=f[i-1][j]+a[i][j];
			path[i][j]=0;
		}
		else
		{
			f[i][j]=f[i][j-1]+a[i][j];
			path[i][j]=1;
		}
	}
	printf("%d\n",f[n][m]);
	printpath(n,m);
	return 0;
} 