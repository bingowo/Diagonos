#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	const int p[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	int a[25],b[25];int c[26];int i,j,t,temp,x,y; char m;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		temp=0;j=0;x=y=1;
		memset(c,0,sizeof(c));
		scanf("%d",&a[0]);
		while(scanf("%c",&m)&&m==',')
			scanf("%d",&a[x++]);
		scanf("%d",&b[0]);
		while(scanf("%c",&m)&&m==',')
			scanf("%d",&b[y++]);
		x--;y--;
		while(x>=0&&y>=0)
		{
			if(a[x]+b[y]+temp<p[j])
			{
				c[j]=a[x]+b[y]+temp;
				temp=0;
			}
			else
			{
				c[j]=a[x]+b[y]+temp-p[j];
				temp=1;
			}
			x=x-1;y=y-1;j++;
		}
		while(x>=0)
		{
			if(a[x]+temp==p[j])			
			{
				c[j++]=a[x]+temp;
				temp=1;
			}
			else 
			{
				c[j++]=a[x]+temp;temp=0;
			}
			x=x-1;			
		}
		while(y>=0)
		{
		if(b[y]+temp==p[j])			
			{
				c[j++]=b[y]+temp;
				temp=1;
			}
			else 
			{
				c[j++]=b[y]+temp;temp=0;
			}
			y=y-1;
		}
		if(temp==1)c[j]=1;
		if(c[j]==0)j--;
		printf("case #%d:\n",i);
		int m;
		for(m=0;m<j;m++)
			printf("%d,",c[m]);
		printf("%d\n",c[j]);
	}
	
	
 } 