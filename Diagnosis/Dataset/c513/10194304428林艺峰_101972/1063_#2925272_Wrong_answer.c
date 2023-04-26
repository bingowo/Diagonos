#include<stdio.h>
#include<stdlib.h>
int main(){
	unsigned long long x, y, ans = 0;
	scanf("%llu%llu", &x, &y);
	while(x != 0 && y != 0){
		if(x < y){
			int c = x;
			x = y;
			y = c;
		}
		ans +=  4 * y * (x / y);
		x = x % y;
	}
	printf("%llu", ans);
	return 0;
}