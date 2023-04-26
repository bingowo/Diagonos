#include <stdio.h>
int w,h,d,c;
int a[300][300] = {0};
int main(void)
{
	scanf("%d %d %d %c",&w,&h,&d,&c);
	d %= 360;
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	if(d==0)
	{
		printf("%d %d\n",w,h); 
		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=w;j++) printf("%d ",a[i][j]);
			printf("\n");
		}
	}
	else if(d==180)
	{
		printf("%d %d\n",w,h); 
		for(int i=h;i>=1;i--)
		{
			for(int j=w;j>=1;j--) printf("%d ",a[i][j]);
			printf("\n");
		}
	}
	else if((d==90 && c=='R') || (d==270 && c=='L'))
	{
		printf("%d %d\n",h,w); 
		for(int i=1;i<=w;i++)
		{
			for(int j=h;j>=1;j--) printf("%d ",a[j][i]);
			printf("\n");
		}
	}
	else
	{
		printf("%d %d\n",h,w); 
		for(int i=w;i>=1;i--)
		{
			for(int j=1;j<=h;j++) printf("%d ",a[j][i]);
			printf("\n");
		}
	}
	return 0;
}