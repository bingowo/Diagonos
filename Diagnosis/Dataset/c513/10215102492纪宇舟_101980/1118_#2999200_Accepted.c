#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int a[205][205],b[205][205];
int main()
{
	int n,m,d;char c;
	scanf("%d %d %d %c",&m,&n,&d,&c);d/=90;d%=4;if(c=='R')d=(4-d)%4;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
	while(d--)
	{
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)b[m-j+1][i]=a[i][j];
		int t=n;n=m;m=t;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)a[i][j]=b[i][j];
	}
	printf("%d %d\n",m,n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			printf("%d",a[i][j]);
			if(j!=m)printf(" ");
		}
		if(i!=n)printf("\n");
	}
	return 0;
}