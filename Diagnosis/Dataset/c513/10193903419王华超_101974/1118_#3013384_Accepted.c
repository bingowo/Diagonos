#include<stdio.h>
#include<limits.h>
#define N 200
void rotating (int L[N][N],int wt,int ht)
{
	int rl[N][N]={0};
	for(int i=0;i<ht;i++)
	{
		for(int j=0;j<wt;j++)
		{
			rl[j][ht-1-i]=L[i][j];
			L[i][j]=0;
		}
	}
	for(int i=0;i<wt;i++)
	{
		for(int j=0;j<ht;j++)
		{
			L[i][j]=rl[i][j];
		}
	}
}
int main()
{
	int w,h,n,t;
	int L[200][200]={0};
	//w=5,h=4
	char c;
	scanf("%d %d %d %c",&w,&h,&n,&c);
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			scanf("%d",&L[i][j]);
		}
	}
	while(n>=360)
	{
		n=n-360;
	}
	if(c=='L')
	{
		n=360-n;
	}
	int mt;
	while(n!=0)
	{
		rotating(L,w,h);
		mt=w;
		w=h;
		h=mt;
		n=n-90;
	}
	printf("%d %d\n",w,h);
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			printf("%d ",L[i][j]);
		}
		printf("\n");
	}
    return 0;
}