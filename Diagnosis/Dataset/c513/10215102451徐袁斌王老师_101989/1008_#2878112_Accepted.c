#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int t,a[100],b,c,d,e=0;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		e=0;
		scanf("%d",&b);
		scanf("%d",&c);
		d=b^c;
		while(d!=0)
		{
			if(d&1)
			{
				e++;d=d>>1;
			}
			else{d=d>>1;}
		}
		a[i]=e;
	}
	for(int i=0;i<t;i++)
	{
		printf("%d\n",a[i]);
	}
	
	return 0;
	
	
 } 