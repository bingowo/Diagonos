#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int a[100]={0},b,c,x=99,y,z=0;
		scanf("%d%d",&b,&y);a[x]=b;
		while(y>1)
		{
			x=99;
			while(x!=-1)
			{
				c=a[x]*b+z;
				a[x]=c%10;
				z=c/10;
				x--;
			}
			y--;
		}
		int j=0;
		while(a[j]==0) j++;
		printf("case #%d:\n",i);
		for(int k=j;k<100;k++) printf("%d",a[k]);
		printf("\n");
		
		
		
		
		
		
	}
	
	
}