#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int t,a[10],b,d,e=0;
	for(int i=0;i<10;i++)
	{
		a[i]=0;
	}
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&b);
		int f,c=~b;
		c=c>>1;
		d=(~(c^b));
		while(d!=0)
		{
			while((d&1)==1)
			{
				e++;d=d>>1;f=b&1;b=b>>1;
			}
			if(e>a[i])
			{
				if(d!=0&&f!=(b&1)){a[i]=e+1;}
				else{a[i]=e;}
			}
			e=0;d=d>>1;b=b>>1;
			if(d!=0&&f!=(b&1)) e=1;
		}
	}
	for(int i=0;i<t;i++)
	{
		printf("case #%d:\n%d\n",i,a[i]);
	}
	
	return 0;
	
	
 } 