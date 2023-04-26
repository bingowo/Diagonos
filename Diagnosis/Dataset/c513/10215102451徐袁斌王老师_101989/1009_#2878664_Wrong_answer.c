#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int t,a[100],c[100],d=0,e=0;
	char b[120];
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		e=0;
		getchar();
		gets(b);int j=0;
		while(b[j]!=0)
		{
			int f=b[j];
			for(int k=0;k<8;k++)
			{	
				if((f&1)!=0)
				{
					e++;f=f>>1;
				}
				else{f=f>>1;}
			}
			j++;d=d+8;
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