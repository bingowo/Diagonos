#include<stdio.h>
#include<stdlib.h>
long long f[60];
long long min(long long x, long long y){
	if(x < y)	return x;
	else	return y;
}
int main(){
	long long x, y, ans = 0;
	scanf("%lld%lld", &x, &y);
	while(x != 0 && y != 0){
		if(x < y){
			int c = x;
			x = y;
			y = c;
		}
		ans +=  4 * y * (x / y);
		x = x % y;
	}
	printf("%lld", ans);
	return 0;
}