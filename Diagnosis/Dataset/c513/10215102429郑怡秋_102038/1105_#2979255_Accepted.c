#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
int cmp(const void*a,const void*b)
{
	int*p1=(int*)a;int*p2=(int*)b;
	return *p1-*p2;
}

int itb(int a[],int n,int k)
{
	int ans=0;
	for(int i=k;i<n;i++) ans=ans*2+a[i];
	for(int i=0;i<k;i++) ans=ans*2+a[i];
	return ans;
}
int main()
{
	int w,h;
	scanf("%d %d",&h,&w);
	int map[110][110];
	int bmap[110][110];
	
	for(int i=0;i<w;i++)
		for(int j=0;j<h;j++)
			scanf("%d",&map[i][j]);
			
	int T[10];
	int bi[10],n=0;
	for(int i=0;i<10;i++) bi[i]=0;
	for(int i=1;i<w-1;i++)
	{
		for(int j=1;j<h-1;j++)
		{
			n=0;
			for(int k=j-1;k<=j+1;k++) 
				{	if(map[i-1][k]>=map[i][j]) bi[n++]=1;
					else bi[n++]=0;}
			if(map[i][j+1]>=map[i][j]) bi[n++]=1;
			else bi[n++]=0;
			for(int k=j+1;k>=j-1;k--) 
				{	if(map[i+1][k]>=map[i][j]) bi[n++]=1;
					else bi[n++]=0;}
			if(map[i][j-1]>=map[i][j]) bi[n++]=1;
			else bi[n++]=0;
			//printf("b1:%d\n",bi[n-1]);
			
			for(int k=0;k<8;k++)
			{
				T[k]=itb(bi,n,k);//printf("%d\n",T[k]);
			}
			qsort(T,8,sizeof(T[0]),cmp);
			
			bmap[i][j]=T[0];
		}
	}
	for(int i=1;i<w-1;i++)
	{
		for(int j=1;j<h-2;j++)
			printf("%d ",bmap[i][j]);
		printf("%d\n",bmap[i][h-2]);
	}
	return 0;
}
