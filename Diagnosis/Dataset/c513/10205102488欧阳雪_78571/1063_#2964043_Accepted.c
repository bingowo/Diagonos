#include<stdio.h>
long long f(long long x,long long y)
{
	if(x==0)
	{
		return 0;
	}
	if(x<y){
		long long temp;
		temp=x;
		x=y;
		y=temp;
	}
	long long n=x/y;
	long long m=x%y;
	long long ans=0;
	x=m;
	ans=y*4*n+f(x,y);
	return ans;
}
int main()
{
	long long x,y;
	scanf("%lld%lld",&x,&y);
	printf("%lld",f(x,y));
	return 0;
}