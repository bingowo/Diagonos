#include<string.h>
#include<stdlib.h>
#include<stdio.h>
const long long maxn = 1e9 + 10;
int main(){
	long long l = 0, r = maxn, mid, n;
	scanf("%lld", &n);
	while(l <= r){
		mid = (l + r) / 2;
		if(mid * mid <= n && (mid + 1) * (mid + 1) > n){
			break;
		}
		else if(mid * mid > n){
			r = mid - 1;
		}
		else if(mid * mid < n){
			l = mid + 1;
		}
	}
	if(mid % 2 == 1){
		long long temp = n - mid * mid;
		if(temp < mid){
			printf("(%lld,%lld)", mid / 2 - temp, mid / 2 + 1);
		}
		else{
			printf("(%lld,%lld)", mid / 2 - mid, mid / 2 + 1 - (temp - mid));
		}
	}
	else{
		long long temp = n - mid * mid;
		if(temp < mid){
			printf("(%lld,%lld)", - mid / 2 + temp, - mid / 2);
		}
		else{
			printf("(%lld,%lld)", - mid / 2 + mid, - mid / 2 + (temp - mid));
		}
	}
	return 0;
}