#include <stdio.h>
#include <stdlib.h>

int main()
{
	int w,h,d;
	char c;
	scanf("%d %d %d ",&w,&h,&d);
	scanf("%c",&c);
	int arr[h][w];
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	int res=(d/90)%4;
	if (c=='L') 
	{
		if(res==1) res=3;
		else if (res==3) res=1;
	}
	if(res%2==1) printf("%d %d\n",h,w);
	else printf("%d %d\n",w,h);
	//printf("%d\n",res);
	switch (res)
	{
		case 0:
			for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				printf("%d",arr[i][j]);
				if(j>=w-1) printf("\n");
				else printf(" ");
			}
			
		}break;
		case 1:
			for(int i=0;i<w;i++)
		{
			for(int j=h-1;j>=0;j--)
			{
				printf("%d",arr[j][i]);
				if(j<1) printf("\n");
				else printf(" ");
			}
		}break;
		case 2:
			for(int i=h-1;i>=0;i--)
		{
			for(int j=w-1;j>=0;j--)
			{
				printf("%d",arr[i][j]);
				if(j<1) printf("\n");
				else printf(" ");
			}
		}break;
		case 3:
			for(int i=w-1;i>=0;i--)
		{
			for(int j=0;j<h;j++)
			{
				printf("%d",arr[j][i]);
				if(j>=h-1) printf("\n");
				else printf(" ");
			}
			
		}break;
	}
	return 0;
		
			
}