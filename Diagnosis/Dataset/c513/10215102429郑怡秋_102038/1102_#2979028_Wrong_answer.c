#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>


int main()
{
	unsigned long long n;
	scanf("%llu",&n);
	unsigned long long k,kk;
	k=(unsigned long long)(sqrt(n));//printf("%llu\n",k);
	kk=k*k;
	long long x,y,x1,y1,x2,y2;
	if(k%2==0)
	{
		x1=-(k/2);y1=x1;
		x2=k/2;y2=x2+1;
		x=x1;y=y1;//printf("%d\n",(x1+k)-x>0);
		unsigned long long tump=n-kk;
		if(tump>=k) 
		{
			x+=k;y+=tump-k;
		}
		else if(tump<k) x+=tump;
//		if(kk!=n) for(;kk<n&&((x1+k)-x>0);kk++,x++);
//		if(kk!=n) for(;kk<n&&((y1+k+1)-y>0);kk++,y++);
	}
	else if(k%2==1)
	{
		x1=(k-1)/2;y1=(k+1)/2;
		x2=-(k+1)/2;y2=x2;
		x=x1;y=y1;//printf("%d\n",x-(x1-k)>0);
		unsigned long long tump=n-kk;
		if(tump>=k) 
		{
			x-=k;y-=tump-k;
		}
		else if(tump<k) x-=tump;		
	}
	printf("(%lld,%lld)",x,y);
	return 0;
	
}