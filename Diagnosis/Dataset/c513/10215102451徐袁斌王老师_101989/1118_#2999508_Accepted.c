#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int a[200][200];
int main()
{
    int w,h,d;
    char c;
    scanf("%d %d %d %c",&w,&h,&d,&c);
    d=d%360;
    for(int i=0;i<h;i++)
    {
		for(int j=0;j<w;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	if((d==90&&c=='R')||(d==270&&c=='L'))
	{
		printf("%d %d\n",h,w);
		for(int i=0;i<w;i++)
		{
			for(int j=h-1;j>=0;j--)
			{
				printf("%d ",a[j][i]);
			}
			printf("\n");
		}
	}
	else if((d==90&&c=='L')||(d==270&&c=='R'))
	{
		printf("%d %d\n",h,w);
		for(int i=w-1;i>=0;i--)
		{
			for(int j=0;j<h;j++)
			{
				printf("%d ",a[j][i]);
			}
			printf("\n");
		}
	}
	else if(d==180)
	{
		printf("%d %d\n",w,h);
		for(int i=h-1;i>=0;i--)
		{
			for(int j=w-1;j>=0;j--)
			{
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}		
	}
	else
	{
		printf("%d %d\n",w,h);
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}		
	}
}