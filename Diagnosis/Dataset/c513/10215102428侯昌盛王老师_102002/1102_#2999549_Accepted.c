#include <stdio.h>
#include <math.h>
int main()
{
	long long n;
	long long int i=1;
	scanf("%lld",&n);
	long long k=i*i;
	if(n==0)
	{
		printf("(0,0)\n");
		goto l;
	}
	if(n==3)
	{
		printf("(-1,0)\n");
	goto l;
	}
	while(k<=n)
	{
		i++;
		k=i*i;
	}
	
	i--;

	k=i*i;
	
	int res=n-k;
	if(i%2==0)
	{
		if(k==n) printf("(%d,%d)\n",-i/2,-i/2);
		else if(res<=i)
		{
			int x=-i/2;
			int y=-i/2;
			x+=res;
			printf("(%d,%d)\n",x,y);
		}
		else{
			int x=-i/2;
			int y=-i/2;
			x+=i;
			y=y+res-i;
			printf("(%d,%d)\n",x,y);
		}
	}
	else{
		if(k==n) printf("(%d,%d)\n",i/2,i/2+1);
		else if(res<=i)
		{
			int x=i/2;
			int y=i/2+1;
			x-=res;
			printf("(%d,%d)\n",x,y);
		}
		else
		{
			int x=i/2;
			int y=i/2+1;
			x-=i;
			y=y-res+i;
			printf("(%d,%d)\n",x,y);
		}
	}
	
	l:return 0;
	
}