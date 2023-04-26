#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
int tr(int x)
{
	if(x==1) return 0;
	else if(x==0) return 1;
}
int main()
{
	int cas;
	scanf("%d",&cas);
	for(int i=0;i<cas;i++)
	{
		int ind[5][5],oud[5][5];
		for(int j=0;j<3;j++)
			for(int k=0;k<3;k++)
			{
				oud[j][k]=1;
				scanf("%d",&ind[j][k]);
			}
		for(int j=0;j<3;j++)
			for(int k=0;k<3;k++)
			{
				if(ind[j][k]%2==1){
				oud[j][k]=tr(oud[j][k]);
				if(j-1>=0) oud[j-1][k]=tr(oud[j-1][k]);
				if(j+1<3) oud[j+1][k]=tr(oud[j+1][k]);
				if(k-1>=0) oud[j][k-1]=tr(oud[j][k-1]);
				if(k+1<3) oud[j][k+1]=tr(oud[j][k+1]);
			}
			}
		printf("case #%d:\n",i);
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<2;k++)
			{
				printf("%d ",oud[j][k]);
			}
			printf("%d\n",oud[j][2]);
		}
				
		
	}
	return 0;
}