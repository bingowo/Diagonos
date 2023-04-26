#include<stdio.h>

long long f(long long x,long long y)
{
	if(x<y)
	{long long t=x;x=y,y=t;}	
	if(y==0)
		return 0;
	return (x/y)*4*y + f(y,x%y);
	
}
int main()
{
	long long x,y;
	scanf("%lld %lld",&x,&y);
	printf("%lld",f(x,y));
	return 0;
}
