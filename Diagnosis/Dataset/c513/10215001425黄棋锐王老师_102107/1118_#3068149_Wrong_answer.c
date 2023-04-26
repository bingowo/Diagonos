#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int main() 
{ 	
	int W,H,D;
	char c;
	scanf("%d %d %d %c",&W,&H,&D,&c);
	int i,j,k,l,n,t;
	int graph[200][200]={0};
	for(i=0;i<H;i++)
		for(j=0;j<W;j++)
			scanf("%d",&graph[i][j]);
	
	D%=360;
	n=D/90;//圈数 
	
	if(c=='R')//顺时针 
	{	for(k=0;k<n;k++)//一圈一圈转换 
		{	int gra[200][200]={0};
			for(i=0;i<W;i++)
				for(j=0;j<H;j++)
				gra[i][j]=graph[H-1-j][i];
			memset(graph,0,W*H);
			t=W,W=H,H=t;
			for(i=0;i<H;i++)
				for(j=0;j<W;j++)
				graph[i][j]=gra[i][j];
		}
	}
	
	if(c=='L')//逆时针 
	{	for(k=0;k<n;k++)//一圈一圈转换 
		{	int gra[200][200]={0};
			for(i=0;i<W;i++)
				for(j=0;j<H;j++)
				gra[i][j]=graph[j][W-1-i];
			memset(graph,0,W*H);
			t=W,W=H,H=t;
			for(i=0;i<H;i++)
				for(j=0;j<W;j++)
				graph[i][j]=gra[i][j];
		}
	}
	
	printf("%d %d",W,H);
	for(i=0;i<H;i++)
	{	for(j=0;j<W;j++)
			printf("%d",graph[i][j]);
		putchar('\n');
	}
		

    return 0;
}