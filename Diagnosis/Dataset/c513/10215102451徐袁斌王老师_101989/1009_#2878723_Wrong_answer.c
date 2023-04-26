#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int t,a[100],c[100],d=0,e=0,g;
	char b[10][120];
	scanf("%d",&t);
	getchar();
	for(int i=0;i<t;i++)
	{
		e=0;d=0;
		gets(b[i]);int j=0;
		while(b[i][j]!=0)
		{
			int f=b[i][j];
			if((b[i][j])>>8==0) g=8;
			else g=16;
			for(int k=0;k<g;k++)
			{	
				if((f&1)!=0)
				{
					e++;f=f>>1;
				}
				else{f=f>>1;}
			}
			j++;d=d+g;
		}
		a[i]=e;
		c[i]=d;
	}
	for(int i=0;i<t;i++)
	{
		for(int k=a[i];k>=1;k--)
		{
			if((a[i]%k==0)&&(c[i]%k==0))
			{
				a[i]=a[i]/k;
				c[i]=c[i]/k;
			}
		}
		printf("%d/%d\n",a[i],c[i]);
	}
	
	return 0;
	
	
 } 