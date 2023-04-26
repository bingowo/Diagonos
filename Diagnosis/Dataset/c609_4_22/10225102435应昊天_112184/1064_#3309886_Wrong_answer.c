#include<stdio.h>
int sum_v(int y,int x);
int main(){
	long long x,y;
	scanf("%lld %lld",&x,&y);
	printf("%lld",sum_v(y,x));
	return 0;
}
int sum_v(int y,int x){
	if(x % y == 0)
		return 4 * x;
	else
		return 4 * y * (x / y) + sum_v(x % y,y);
}