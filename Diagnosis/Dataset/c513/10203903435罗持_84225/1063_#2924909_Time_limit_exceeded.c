#include <stdio.h>
#include <stdlib.h>
long long x,y;
long long res = 0;
void helper(long long x,long long y)
{
	if(y==0){
		return;
	}
	res += y*4;
	x -= y;
	if(x<y){
		long long temp = x;
		x = y;
		y = temp;
	}
	helper(x,y);
}
int main(void)
{
	scanf("%lld %lld",&x,&y);
	if(x<y){
		long long temp = x;
		x = y;
		y = temp;
	}
	helper(x,y);
	printf("%lld",res);
	return 0;
}