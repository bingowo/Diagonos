#include<stdio.h>
#include<math.h>
#define MAX 800
int TwoToTen(int*b)//固定8位 
{   
        int sum=0;
        for(int i=0,j=7;i<8;i++,j--)
        {
        	sum+=b[i]*pow(2,j);
		}
        
        return sum;
}

int main()
{
	int W,H;
	scanf("%d%d",&W,&H);
	int i=0,j=0;
	int a[MAX][MAX];
	for(i=0;i<H;i++)
	{
		for(j=0;j<W;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	int ans[MAX]={0},q=0;
	for(i=1;i<H;i++)
	{
		for(j=1;j<W;j++)
		{

		if((i-1)>=0&&(i+1)<H&&(j-1)>=0&&(j+1)<W)//中心点 
		{
			int b[MAX]={0};
		    int t=0,cent=0;
			cent=a[i][j];
		//	printf("cent:%d\n",cent);
			if(a[i-1][j-1]>=cent)
			{
				b[t]=1;
			}
			t++;
			if(a[i-1][j]>=cent)
			{
				b[t]=1;
			}
			t++;
			if(a[i-1][j+1]>=cent)
			{
				b[t]=1;
			}
			t++;
			if(a[i][j+1]>=cent)
			{
				b[t]=1;
			}
			t++;
		//	printf("test:%d\n",t);
			if(a[i+1][j+1]>=cent)
			{
				b[t]=1;
			}
			t++;
			if(a[i+1][j]>=cent)
			{
				b[t]=1;
			}
			t++;
			if(a[i+1][j-1]>=cent)
			{
				b[t]=1;
			}
			t++;
			if(a[i][j-1]>=cent)
			{
				b[t]=1;
			}
			t++;
		/*	printf("b:");
			for(int x=0;x<8;x++)
			{
				printf("%d ",b[x]);
			}
			printf("\n");*/
			
			int min=500;
			
			for(int k=0;k<8;k++)//旋转 
			{
				int tp[10]={0};
				int n=0,m=0;
				int temp=0;
				for(n=k;n<8;n++)
				{
					tp[m]=b[n];
					m++;
				}
				for(n=0;n<k;n++)
				{
					tp[m]=b[n];
					m++;
				}
				temp=TwoToTen(tp);
				if(min>temp)
				{
					min=temp;
				}
			}
			ans[q++]=min;
		}
	}
	}
//	printf("q:%d\n",q);
	q=0;
	for(i=0;i<H-2;i++)
	{
		for(j=0;j<W-2;j++)
		{
			printf("%d ",ans[q]);
		    q++;
		}
		printf("\n");
	}
}