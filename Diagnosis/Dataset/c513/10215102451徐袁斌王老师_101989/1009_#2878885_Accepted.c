#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int t,a[100],c[100],d=0,e=0;
	char b[10][120];
	scanf("%d",&t);
	getchar();
	for(int i=0;i<t;i++)
	{
		e=0;d=0;
		gets(b[i]);int j=0;
		while(b[i][j]!=0)
		{
			char f=b[i][j];
			while(f!=0)
			{	
				e++;f=f&(f-1);
			}
			d=d+8;j++;
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