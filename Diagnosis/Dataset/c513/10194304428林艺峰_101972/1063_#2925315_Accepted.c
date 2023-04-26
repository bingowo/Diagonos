#include<stdio.h>
#include<stdlib.h>
long long swap(long long *pa, long long *pb){
	long long p = *pa;
	*pa = *pb;
	*pb = p;
}
int main(){
	long long x, y, ans = 0;
	scanf("%lld%lld", &x, &y);
	while(x != 0 && y != 0){
		if(x < y){
			swap(&x, &y);
		}
		ans +=  4 * y * (x / y);
		x %= y;
	}
	printf("%lld", ans);
	return 0;
}