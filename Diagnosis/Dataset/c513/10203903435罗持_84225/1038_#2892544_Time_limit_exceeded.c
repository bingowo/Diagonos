#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int a[300][300] = {0};
int n,m,k;
int min(int x,int y)
{
	if(x<y) return x;
	else return y;
}
int cal(int x,int y,int opt,int len)
{
	int sum = 0;
	int l = len;
	if(opt==1)
	{
		for(int i=x;i<x+len;i++)
		{
			for(int j=y;j<y+l;j++)
			{
				sum += a[i][j];
			}
			l--;
		}
	}
	if(opt==2)
	{
		for(int i=x;i<x+len;i++)
		{
			for(int j=y+len-1;j>=y+len-l;j--)
			{
				sum += a[i][j]; 
			}
			l--;
		}
	}
	if(opt==3)
	{
		int d = 0;
		for(int i=x;i<x+len;i++)
		{
			for(int j=y;j<=y+d;j++)
			{
				sum += a[i][j];
			}
			d++;
		}
	}
	if(opt==4)
	{
		for(int i=x;i<x+len;i++)
		{
			for(int j=y+len-1;j>=y+l-1;j--)
			{
				sum += a[i][j];
			}
			l--;
		}
	}
	if(sum >= k) return 1;
	else return 0;
}
int main(void)
{
	int res = 0;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	int lim = min(n,m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int l=2;l<=lim;l++)
			{
				if(i+l-1<=n && j+l-1<=m)
				{
					if(cal(i,j,1,l))
					{
						res++;
					}
					
				}
			}
		}
	}
	//printf("%d\n",res);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int l=2;l<=lim;l++)
			{
				if(i+l-1<=n && j+l-1<=m)
				{
					if(cal(i,j,2,l))
					{
						res++;
					}
					
				}
			}
		}
	}
	//printf("%d\n",res);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int l=2;l<=lim;l++)
			{
				if(i+l-1<=n && j+l-1<=m)
				{
					if(cal(i,j,3,l))
					{
						res++;
					}
					
				}
			}
		}
	}
	//printf("%d\n",res);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int l=2;l<=lim;l++)
			{
				if(i+l-1<=n && j+l-1<=m)
				{
					if(cal(i,j,4,l))
					{
						res++;
					}
					
				}
			}
		}
	}
	printf("%d",res);
	return 0;
}