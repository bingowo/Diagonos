#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>

int min(int x,int y)
{
	if(x<y) return x;
	else return y;
}

int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int a[210][210],F[210][210];
	
	for(int i=0;i<n;i++) 
		for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
			
	int ans=0,tump=0;
	
	for(int j=0;j<n;j++) F[j][0]=a[j][0];
	for(int i=0;i<n;i++) 
		for(int j=1;j<m;j++)
			F[i][j]=F[i][j-1]+a[i][j];
	//左上角以下三角形式遍历 
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{	ans=0;
			for(int x=i,y=j;x<n&&y<m;x++,y++)
			{
				if(j>0) ans+=F[x][y]-F[x][j-1];
				else ans+=F[x][y];
				if(ans>=k)
				{
					tump+=min(n-x,m-y);
					break;
				}
				//printf("左上角: %d\n",tump);
			}
			
		}
	//右上角以次下三角遍历 
	for(int i=0;i<n;i++)
		for(int j=m-1;j>=0;j--)
		{	ans=0;
			for(int x=i,y=j;x<n&&y>=0;x++,y--)
			{
				if(y>0) ans+=F[x][j]-F[x][y-1];
				else ans+=F[x][j];
				if(ans>=k)
				{
					tump+=min(n-x,y+1);
					break;
				}//printf("右上角: %d\n",tump);
			}
			
		}
	
	//左下角以次上三角遍历
	for(int i=n-1;i>=0;i--)
		for(int j=0;j<m;j++)
		{	ans=0;
			for(int x=i,y=j;x>=0&&y<m;x--,y++)
			{
				if(j>0) ans+=F[x][y]-F[x][j-1];
				else ans+=F[x][y];
				if(ans>=k)
				{
					tump+=min(x+1,m-y);
					break;
				}//printf("左下角: %d\n",tump);
			}
			
		}
	//右下角以上三角遍历 
	for(int i=n-1;i>=0;i--)
		for(int j=m-1;j>=0;j--)
		{	ans=0;
			for(int x=i,y=j;x>=0&&y>=0;x--,y--)
			{
				if(j>0) ans+=F[x][j]-F[x][y-1];
				else ans+=F[x][y];
				if(ans>=k)
				{
					tump+=min(x+1,y+1);
					break;
				}//printf("右下角: %d\n",tump);
			}
			
		}
	printf("%d",tump);
	return 0;
}