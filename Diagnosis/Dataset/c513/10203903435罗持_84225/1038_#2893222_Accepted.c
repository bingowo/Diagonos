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
int cal1(int x,int y,int len)
{
	int sum = 0;
	int l = len;
	for(int i=x;i<x+len;i++)
	{
		for(int j=y;j<y+l;j++)
		{
			sum += a[i][j];
		}
		l--;
	}
	if(sum>=k) return 1;
	else return 0;
}
int cal2(int x,int y,int len)
{
	int sum = 0;
	int l = len;
	for(int i=x;i<x+len;i++)
	{
		for(int j=y-l+1;j<=y;j++)
		{
			sum += a[i][j];
		}
		l--;
	}
	if(sum>=k) return 1;
	else return 0;
}
int cal3(int x,int y,int len)
{
	int sum = 0;
	int d = 0;
	for(int i=x-len+1;i<=x;i++)
	{
		for(int j=y;j<=y+d;j++)
		{
			sum += a[i][j];
		}
		d++;
	}
	if(sum>=k) return 1;
	else return 0;
}
int cal4(int x,int y,int len)
{
	int sum = 0;
	int d = 0;
	for(int i=x-len+1;i<=x;i++)
	{
		for(int j=y-d;j<=y;j++)
		{
			sum += a[i][j];
		}
		d++;
	}
	if(sum>=k) return 1;
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
					if(cal1(i,j,l))
					{
						res++;
						int li = n-i-l+1;
						int lj = m-j-l+1;
						res += min(li,lj);
						break;
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
				if(i+l-1<=n && j-l+1>=1)
				{
					if(cal2(i,j,l))
					{
						res++;
						int li = n-i-l+1;
						int lj = j-l;
						res += min(li,lj);
						break;
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
				if(i-l+1>=1 && j+l-1<=m)
				{
					if(cal3(i,j,l))
					{
						res++;
						int li = i-l;
						int lj = m-j-l+1;
						res += min(li,lj);
						break;
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
				if(i-l+1>=1 && j-l+1>=1)
				{
					if(cal4(i,j,l))
					{
						res++;
						int li = i-l;
						int lj = j-l;
						res += min(li,lj);
						break;
					}
				}
			}
		}
	}
	printf("%d",res);
	return 0;
}