#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
	double  dis;//与最后一辆车距离 
	double speed;
	double di;//与终点距离
	double time;//到终点时间 
}CAR;

int cmp(const void*a,const void*b)
{
	CAR aa=*(CAR*)a;
	CAR bb=*(CAR*)b;
	return aa.di-bb.di;
}

int main() 
{ 	int t,T;
	scanf("%d",&T);
	for(t=0;t<T;t++)
 {
 	int graph[10][10]={0};
 	int r,c,n,k,ant=0;
 	scanf("%d %d %d %d",&r,&c,&n,&k);
 	int i,j,l;
 	for(i=0;i<n;i++)
 	{	int x,y;
 		scanf("%d %d",&x,&y);
 		graph[x-1][y-1]=1;
	 }
 	
 	int w,h,a,b;
 	for(h=1;h<=r;h++)//长 
 		for(w=1;w<=c;w++)//宽 
 			for(i=0;i<=r-h;i++)//矩形位置 左上角从上往下移动 
 				for(j=0;j<=c-w;j++)//矩形位置  左上角从左往右移动 
 				{	int cn=0;
 					for(a=i;a<i+h;a++)
 						for(b=j;b<j+w;b++)
 							if(graph[a][b]==1) cn++;
 					if(cn==k) ant++;
				}	
 						
 	printf("case #%d:\n",t);
 	printf("%d\n",ant);
 } 
    return 0;
}