#include<stdio.h>
int sum_v(int y,int x);
int main(){
	long long x,y;
	scanf("%lld %lld",&x,&y);
	printf("%lld",sum_v(y,x));
	return 0;
}
int sum_v(int y,int x){
	int sum = 0;
	if(x % y == 0)
		return sum + 4 * x;
	else
		return sum + sum_v(x%y,y);
}