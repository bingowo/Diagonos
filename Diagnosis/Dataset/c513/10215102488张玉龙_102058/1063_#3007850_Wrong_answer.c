#include<stdio.h>
long long f(long long x,long long y)
{
	long long result=0;
	if(x==0||y==0)
		result=0;
	else if(x==y)
		result=4*x;
	else if(x<y)
		result+=4*x*y/x+f(x,y%x);
	else if(x>y)
		result+=4*y*x/y+f(x%y,y);
	return result;
}
int main()
{
	long long x,y;
		scanf("%lld%lld",&x,&y);
		printf("%lld",f(x,y));
	return 0;
}