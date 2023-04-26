#include<stdio.h>
#include<stdlib.h>
int tf(int a)
{
	if(a==1)
	{
		a=0;
	}
	else a=1;
	return a;
}
void p(int state[3][3],int i,int j)
{
	state[i][j]=tf(state[i][j]);
	
	if(i+1<=2)state[i+1][j]=tf(state[i+1][j]);
	if(j+1<=2)state[i][j+1]=tf(state[i][j+1]);
	if(i-1>=0)state[i-1][j]=tf(state[i-1][j]);
	if(j-1>=0)state[i][j-1]=tf(state[i][j-1]);
	
}
int main()
{
	int T;
	scanf("%d",&T);
	int trans[3][3]={0};
	for(int t=0;t<T;t++)
	{
		int state[3][3]=
        {
	        1,1,1,
	        1,1,1,
	        1,1,1
        };//初始状态
		int i=0,j=0;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				scanf("%d",&trans[i][j]);
			}
		}
		
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(trans[i][j]>0)
				{
					for(int k=0;k<trans[i][j];k++)
					{
						p(state,i,j);
					}
				}
			}
		}
		
		printf("case #%d:\n",t);
		for(i=0;i<3;i++)
		{
			for(j=0;j<2;j++)
			{
				printf("%d ",state[i][j]);
			}
			printf("%d\n",state[i][2]);
		}
	}
 } 
