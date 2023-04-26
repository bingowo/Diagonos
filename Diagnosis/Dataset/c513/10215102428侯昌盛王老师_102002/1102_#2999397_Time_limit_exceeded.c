#include <stdio.h>
typedef struct{
	int x,y;
}point;
int main()
{
	long long n,i,sum=0;
	int j=0;
	
	char s[5]={'R','U','L','D'};
	scanf("%lld",&n);

	point p;
	p.x=0;p.y=0;
	int k=1,flag=0;
	for(i=1;sum+i*2<=n;i++)
	{
		
			if(s[k%4]=='U'){
				p.y+=i;p.x-=i;
				
			}
			else if(s[k%4]=='L')
			{
				p.x-=i;
				p.y-=i; 
			}
			else if(s[k%4]=='D')
			{
				p.y-=i;
				p.x+=i; 
			}
			else if(s[k%4]=='R')
			{
				p.x+=i;
				p.y+=i; 
			}
			sum=sum+i*2;
			k+=2;
		
		
		
	}

	if(sum+i*2>n)
	{
		long long res=n-sum;
		if(sum+i<=n)
		{
			sum+=i; 
			res=n-sum;
			if(s[k%4]=='U'){
				p.y=p.y+i;
				p.x-=res;
				
			}
			else if(s[k%4]=='L')
			{
				p.x-=i;
				p.y-=res;
				
			}
			else if(s[k%4]=='D')
			{
				p.y-=i;
				p.x+=res;
				
			}
			else if(s[k%4]=='R')
			{
				p.x+=i;
				p.y+=res;
			
			}
		
		}
		else{
		
			if(s[k%4]=='U'){
					p.y+=res;
				
				}
				else if(s[k%4]=='L')
				{
					p.x-=res;
				
				}
				else if(s[k%4]=='D')
				{
					p.y-=res;
			
				}
				else if(s[k%4]=='R')
				{
					p.x+=res;
				
				}
			}
			
	}

	


	printf("(%d,%d)\n",p.x,p.y);
	return 0;
}