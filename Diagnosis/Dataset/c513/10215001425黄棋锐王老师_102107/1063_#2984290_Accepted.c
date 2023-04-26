#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long cal(long long x,long long y)
{   long long ti=0;
	long long co=x/y;
	long long r=x%y;
	if(r!=0) ti=ti+4*co*y+cal(y,r);
	else ti+=4*co*y;
	return ti;
	
}
int main()
{  long long x,y;
	scanf("%lld %lld",&x,&y);
	long long t=cal(x,y);
	printf("%lld",t);
	return 0;
}