#include <stdio.h>
#include <stdlib.h>

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int zs=n/m;
		n=n-zs*m;
		n*=10;
		int ans[1000],yushu[1000];
		for(int j=0;j<1000;j++) yushu[i]=0,ans[j]=0;
		int r=0;
		int k=0,begin=0,end=0;
		do
		{
			r=n%m;
			for(int j=0;j<k;j++)
			{
				if(r==yushu[j])
				{
					begin=j;end=k-1;
					break;
				}
			}
			
			yushu[k]=r;
			ans[k]=n/m;
			n=r*10;
			
			k++;
		}while(r!=0&&begin==0);
		printf("case #%d:\n%d.",i,zs);
		for(int l=0;l<k;l++) printf("%d",ans[l]);
		printf("\n");
		if(begin!=0) 
		{
			printf("%d-%d\n",begin+2,end+2);
		}
		
	}
	
	return 0;
 } 