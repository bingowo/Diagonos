#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int t,a[10],b,c,d;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&b);d=b%2;
		int sum=1,e=1;
		if(d==1) 
		{while(b>1)
		{
			c=b%2;
			b=b/2;
			if((c==1)&&(b%2==0)&&((b/2)%2==1))
			{
				e=e+2;
				if(e>sum) sum=e;
				b=b/2;
			}
			else
			{
				e=1;
			}
		}}
		
		if(d==0) 
				{while(b>1)
				{
					c=b%2;
					b=b/2;
					if((c==0)&&(b%2==1)&&((b/2)%2==0))
					{
						e=e+2;
						b=b/2;
						if(e>sum&&(b/2)>1) sum=e;
						if(e>sum&&(b/2)<=1) sum=e-1;
					}
					else
					{
						e=1;
					}
				}
				}
		a[i]=sum;
	}
	for(int i=0;i<t;i++)
	{
		printf("case #%d:\n%d\n",i,a[i]);
	}
	
	return 0;
	
	
 } 