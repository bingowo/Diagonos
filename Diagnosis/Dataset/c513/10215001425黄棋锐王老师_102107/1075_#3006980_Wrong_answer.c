#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
  typedef struct
  {
  	int val;
  	char dir;
  }ELE;
  ELE a[250][250];//每个位置 
  void shortest(int M,int N)//计算到每个位置最小距离 ,M-行，N-列 
{   int i,j;
  	for(i=1;i<M;i++)//第一列 
  	{  a[i][0].val+=a[i-1][0].val;
  		a[i][0].dir='D';
	}
  	for(j=1;j<N;j++)//第一行 
    	{  a[0][j].val+=a[0][j-1].val;
  	       a[0][j].dir='R';
  	   
	    } 
		for(i=1;i<M;i++)//其他位置 
			for(j=1;j<N;j++)
		 {	if(a[i][j-1].val<a[i-1][j].val)
			 {
			 a[i][j].val+=a[i][j-1].val;
			 a[i][j].dir='R';
		     }
			else //输入保证答案唯一 
			{
			 a[i][j].val+=a[i-1][j].val;
			 a[i][j].dir='D';
			}
		 }
}    
   void packpath(int M,int N,int x,int y)//输出到每个位置的最短路程 
   {   if(x==0&&y==0) return;
		if(a[x][y].dir=='D')
		{  packpath(M,N,x-1,y);
			putchar('D');
		}
   		else
		  {
   			packpath(M,N,x,y-1);
   			putchar('R');
		   }
   }
int main()
{    int i,j,M,N;
	scanf("%d %d\n",&M,&N);
	for(i=0;i<=M;i++)
	{ for(j=0;j<=N;j++) 
		{scanf("%d",&a[i][j].val);
		   a[i][j].dir=0;
		} 
	} 
	shortest(M,N);
	packpath(M,N,M-1,N-1);
	putchar('\n');
	return 0;
}