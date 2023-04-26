#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int t,x[100]={0},y[100]={0};
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<100;j++) {x[j]=0;y[j]=0;}
		int s,ans=0;
		scanf("%d",&s);
		for(int j=0;j<s;j++)
		{
			scanf("%d%d",&x[j],&y[j]);
		}
		for(int j=0;j<s;j++)
		{
			for(int k=0;k<s;k++)
			{
				if(k==j) continue;
				else if(x[j]==y[k]) ans++;
				else if(x[j]==x[k]&&y[j]!=y[k]) ans++;
			}
		}
		if(ans==0) printf("Lucky dxw!\n");
		else printf("Poor dxw!\n");
		
	}
		
	
}