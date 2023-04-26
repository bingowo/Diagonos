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
	k=int(sqrt(n));//printf("%llu\n",k);
	kk=k*k;
	long long x,y,x1,y1,x2,y2;
	if(k%2==0)
	{
		x1=-(k/2);y1=x1;
		x2=k/2;y2=x2+1;
		x=x1;y=y1;
		if(kk!=n) for(x=x1;kk<n&&x<x1+k;kk++,x++);
		if(kk!=n) for(y=y1;kk<n&&y<y1+k+1;kk++,y++);
	}
	else if(k%2==1)
	{
		x1=(k-1)/2;y1=(k+1)/2;
		x2=-(k+1)/2;y2=x2;
		x=x1;y=y1;
		if(kk!=n) for(x=x1;kk<n&&x>x1-k;x--,kk++);
		if(kk!=n) for(y=y1;kk<n&&y>y1-k-1;y--,kk++);
	}
	printf("(%lld,%lld)",x,y);
	return 0;
	
}