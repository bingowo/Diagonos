#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int f(int x)
{
	if(x==1) return 1;
	if(x==2) return 1;
	else return f(x-1)+f(x-2);
}
int main()
{
	int a,n,m,x,b=2,c=1,d,ans=0;
	scanf("%d%d%d%d",&a,&n,&m,&x);
	n--;
	if(x==1||x==2)
	{
		printf("%d",a);
	}
	else 
	{
		for(int i=1;i<n-3;i++)
		{
			b=b+f(i);
			c=c+f(i+1);
		}
		d=(m-a*b)/c;
		ans=2*a+d;
		for(int i=1;i<x-3;i++)
		{
			ans=ans+f(i)*a+f(i+1)*d;
		}
		printf("%d",ans);
				
	}

	return 0;
	
 } 