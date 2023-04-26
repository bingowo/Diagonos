#include <stdio.h>

unsigned long long cal(unsigned long long x,unsigned long long y)
{
	if(x>y){
		unsigned long long t;
		t=x;
		x=y;
		y=t;
	}
	if(x==y){
		return 4*x;
	}
	return 4*x+cal(x,y-x);
}
int main()
{
	unsigned long long x,y;
	scanf("%llu %llu",&x,&y);
	if(x%y==0){
		printf("%llu",4*x);
	}
	else{
		printf("%llu\n",cal(x,y));
	}
	return 0;
}