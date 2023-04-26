#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int**p;
	int m,n;
	scanf("%d%d",&m,&n);
	p=(int**)malloc(sizeof(int*)*n);
	for(int i=0;i<m;i++) p[i]=(int*)malloc(sizeof(int)*m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&p[i][j]);
		}
	}
	for(int i=1;i<n-1;i++)
	{
		for(int j=1;j<m-1;j++)
		{
			int x[8];
			if(p[i-1][j-1]>=p[i][j]) x[0]=1;
			else x[0]=0;
			if(p[i-1][j]>=p[i][j]) x[1]=1;
			else x[1]=0;
			if(p[i-1][j+1]>=p[i][j]) x[2]=1;
			else x[2]=0;
			if(p[i][j-1]>=p[i][j]) x[7]=1;
			else x[7]=0;
			if(p[i][j+1]>=p[i][j]) x[3]=1;
			else x[3]=0;
			if(p[i+1][j-1]>=p[i][j]) x[6]=1;
			else x[6]=0;
			if(p[i+1][j]>=p[i][j]) x[5]=1;
			else x[5]=0;
			if(p[i+1][j+1]>=p[i][j]) x[4]=1;
			else x[4]=0;
			int ans=256,d=0;
			for(int k=0;k<8;k++)
			{
				for(int o=k,u=0;u<8;u++)
				{
					d=d*2+x[o];
					if(o!=7) o++;
					else o=0;
				}
				if(d<ans) ans=d;
				d=0;
			}
			if(j!=m-2) printf("%d ",ans);
			else printf("%d\n",ans);
		}
	}	
	
	
	for(int i=0;i<n;i++) free(p[i]);
	free(p);
}