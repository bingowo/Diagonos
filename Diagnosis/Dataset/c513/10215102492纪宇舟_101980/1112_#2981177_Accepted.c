#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int main()
{
	int a[5][1005];
	memset(a,-1,sizeof(a));
	a[0][0]=1;
	for(int i=1;i<=4;i++)
	for(int j=0;j<=1000;j++)
	{
		a[i][j]=a[i-1][j];
		for(int k=1;k<=j/i;k++) 
		{
			if(a[i-1][j-k*i]!=-1)
			{
				if(a[i][j]==-1)a[i][j]=0;
				a[i][j]+=a[i-1][j-k*i];
			}
		}
	}
	int t,x;scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&x);
		printf("%d\n",a[4][x]);
	}
	return 0;
} 