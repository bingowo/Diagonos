#include<stdio.h>
long long gcd(long long x,long long y);
int main(){
	long long x,y;
	scanf("%lld %lld",&x,&y);
	long long ans = gcd(x,y);
	printf("%lld\n",4 * x * (y / ans));
	return 0;
}
long long gcd(long long x,long long y){
	if(x % y == 0)
		return y;
	else
		return gcd(y,x%y);
}