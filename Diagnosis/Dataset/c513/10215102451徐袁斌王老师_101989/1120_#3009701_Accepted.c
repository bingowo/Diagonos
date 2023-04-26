#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int t,r,c,n,k,a[10][10],b,d,e;
	scanf("%d",&t); 
    for(int i=0;i<t;i++)
	{
		e=0;
		for(int j=0;j<10;j++)
		{
			for(int o=0;o<10;o++){a[j][o]=0;}
		}
		scanf("%d%d%d%d",&r,&c,&n,&k);
		for(int j=0;j<n;j++)
		{
			scanf("%d%d",&b,&d);
			a[b-1][d-1]=1;
		}
		for(int j=0;j<r;j++)
		{
			for(int o=0;o<c;o++)
			{
				for(int q=j;q<r;q++)
				{
					for(int w=o;w<c;w++)
					{
						int ans=0;
						for(int z=j;z<=q;z++)
						{
							for(int x=o;x<=w;x++)
							{
								ans=ans+a[z][x];
							}
						}
						if(ans>=k){e++;}
					}
				}
			}
		}
		printf("case #%d:\n%d\n",i,e);
		
	} 
    
    return 0;
}