#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int min(int x,int y)
{
	if(x<y) return x;
	else return y;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	long long a[310][310];
	long long s[310][310];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
			s[i][j]=0;
		}
	}
	s[0][0]=a[0][0];
	for(int i=1;i<m;i++) s[0][i]=s[0][i-1]+a[0][i];//,printf("%d ",s[0][i]);
	for(int i=1;i<n;i++) s[i][0]=s[i-1][0]+a[i][0];//,printf("%d ",s[i][0]);
	for(int i=1;i<n;i++) 
	{
		for(int j=1;j<m;j++)
		{
			s[i][j]=min(s[i-1][j],s[i][j-1])+a[i][j];//printf("%d ",s[i][j]);
		}
	}
	char ans[220];
	int k=0;
	int x=n-1,y=m-1;
	while(x>=0&&y>=0)
	{//printf("\n%d %d %d %d\n",x,n,y,m);
		if(x==0&&y==0) 
		{
			break;
		}
		else if(x==0)
		{
			ans[k++]='R';//printf("2");
			y--; 
		}
		else if(y==0)
		{
			ans[k++]='D';
			x--;
		}
		else
		{
			if(s[x][y-1]<s[x-1][y])
			{
				ans[k++]='R';//printf("1");
				y--;
			}
			else
			{
				ans[k++]='D';//printf("0");
				x--;
			}
		}
	}
	ans[k]='\0';
	printf("%lld\n",s[n-1][m-1]);
	for(int i=k-1;i>=0;i--) printf("%c",ans[i]);
	printf("\n");
	return 0;
}