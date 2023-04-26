#include <stdio.h>

int main()
{
	int W,H,w,h;
	long long D;
	char c;
	scanf("%d %d %lld %c",&W,&H,&D,&c);
	int image[H][W];
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++)
		{
			scanf("%d",&image[i][j]);
		}
	}
	if(c=='L')
	{
		if(D%360 == 0) D=0;
		if(D%360 == 90) D=270;
		if(D%360 == 180) D=180;
		if(D%360 == 270) D=90;
	}
	D = D % 360;
	if(D==0)
	{
		w = W;
		h = H;
		printf("%d %d\n",w,h);
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				printf("%d ",image[i][j]);
			}
			printf("\n");
		}
	}
	else if(D==90)
	{
		w = H;
		h = W;
		printf("%d %d\n",w,h);
		for(int j=0;j<h;j++)
		{
			for(int i=w-1;i>-1;i--)
			{
				printf("%d ",image[i][j]);
			}
			printf("\n");
		}
	}
	else if(D==180)
	{
		w = W;
		h = H;
		printf("%d %d\n",w,h);
		for(int i=h-1;i>-1;i--)
		{
			for(int j=w-1;j>-1;j--)
			{
				printf("%d ",image[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		w = H;
		h = W;
		printf("%d %d\n",w,h);
		for(int j=h-1;j>-1;j--)
		{
			for(int i=0;i<w;i++)
			{
				printf("%d ",image[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}