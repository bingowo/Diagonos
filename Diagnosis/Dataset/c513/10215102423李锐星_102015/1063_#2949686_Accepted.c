#include <stdio.h>

unsigned long long cal(unsigned long long x,unsigned long long y)
{
	if(x>y){
		unsigned long long t;
		t=x;
		x=y;
		y=t;
	}
	if(y%x==0){
		return 4*y;
	}
	return 4*x*(y/x)+cal(y%x,x);
}
int main()
{
	unsigned long long x,y;
	scanf("%llu %llu",&x,&y);
	printf("%llu\n",cal(x,y));
	return 0;
}