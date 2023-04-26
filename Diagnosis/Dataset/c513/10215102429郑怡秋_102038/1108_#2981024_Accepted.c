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
		int ans[1000],yushu[1000];yushu[0]=n/10;//printf("%d\n",yushu[0]);
		//for(int j=1;j<1000;j++) yushu[i]=0,ans[j]=0;
		int r=0;
		int k=0,begin=-1,end=0;
		do
		{
			r=n%m;
			yushu[k+1]=r;
			ans[k]=n/m;
			n=r*10;
			
			k++;
			for(int j=0;j<k;j++)
			{
				if(r==yushu[j])
				{
					ans[k+1]=r*10/m;
					begin=j+1;end=k;
					break;
				}
			}
			
		}while(r!=0&&begin==-1);
		printf("case #%d:\n%d.",i,zs);
		for(int l=0;l<k;l++) printf("%d",ans[l]);
		printf("\n");
		if(begin!=-1) 
		{
			printf("%d-%d\n",begin,end);
		}
		
	}
	
	return 0;
 } 