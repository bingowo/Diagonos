#include <stdio.h>
#include <string.h>
int main()
{
	int w,h,d,w1,h1;
	char c;
	scanf("%d %d %d %c",&w,&h,&d,&c);
	if((d/90)%2!=0)
	{
		w1=h;h1=w;
	}
	else 
	{
		w1=w;h1=h;
	}
	int s[201][201]={0};
	int i=0,j=0;
	for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++) scanf("%d",&s[i][j]);
	}
	int d1;
	d1=d%360;
	if(c=='L') d1=360-d1;
	printf("%d %d\n",w1,h1);
	if(d1==0) 
	{
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++) printf("%d ",s[i][j]);
			printf("\n");
		}
	}
	else if(d1==90)
	{
		for(j=0;j<w;j++)
		{
			for(i=h-1;i>=0;i--) printf("%d ",s[i][j]);
			printf("\n");
		}
	}
	else if(d1==180)
	{
		for(i=h-1;i>=0;i--)
		{
			for(j=w-1;j>=0;j--) printf("%d ",s[i][j]);
			printf("\n");
		}
	}
	else if(d1==270)
	{
		for(j=w-1;j>=0;j--)
		{
			for(i=0;i<h;i++) printf("%d ",s[i][j]);
			printf("\n"); 
		}
	}
	return 0;
}