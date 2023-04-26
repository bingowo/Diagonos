#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 1000000007

typedef struct
{	
	long long int x;
	long long int y;
}point;


int temp(int x)
{
	if(x==0) return 1;
	else return 0;
}

int main() 
{ 	int t,T;
	scanf("%d\n",&T);
	for(t=0;t<T;t++)
{	int gra[3][3]={0};
	int i,j,flag,k;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++) gra[i][j]=1;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
	{	scanf("%d",&flag);
		for(k=0;k<flag;k++)
		{
			gra[i][j]=temp(gra[i][j]);
			if(i==0)
			{
				if(j==0) gra[0][1]=temp(gra[0][1]),gra[1][0]=temp(gra[1][0]);
				if(j==1) gra[0][0]=temp(gra[0][0]),gra[1][1]=temp(gra[1][1]),gra[0][2]=temp(gra[0][2]);
				if(j==2) gra[0][1]=temp(gra[0][1]),gra[1][2]=temp(gra[1][2]);
			}
			
			if(i==1)
			{
				if(j==0) gra[0][0]=temp(gra[0][0]),gra[2][0]=temp(gra[2][0]),gra[1][1]=temp(gra[1][1]);
				if(j==1) gra[0][1]=temp(gra[0][1]),gra[1][0]=temp(gra[1][0]),gra[1][2]=temp(gra[1][2]),gra[2][1]=temp(gra[2][1]);
				if(j==2) gra[0][2]=temp(gra[0][2]),gra[1][1]=temp(gra[1][1]),gra[2][2]=temp(gra[2][2]);
			}
			
			if(i==2)
			{
				if(j==0) gra[1][0]=temp(gra[1][0]),gra[2][1]=temp(gra[2][1]);
				if(j==1) gra[1][1]=temp(gra[1][1]),gra[2][0]=temp(gra[2][0]),gra[2][2]=temp(gra[2][2]);
				if(j==2) gra[1][2]=temp(gra[1][2]),gra[2][1]=temp(gra[2][1]);
			}
		}
	}
		
		
		printf("case #%d:\n",t);
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
			{
				printf("%d",gra[i][j]);
				if(j==2) putchar('\n');
				else putchar(' ');
			}
		
}
	return 0;
}