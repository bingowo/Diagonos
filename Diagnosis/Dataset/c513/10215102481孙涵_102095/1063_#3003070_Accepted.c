#include <stdlib.h>
#include <stdio.h>

void swap(long long int *a, long long int *b);

int main(){
	long long int a, b, c;
	unsigned long long int ans;
	scanf("%lld %lld",&a,&b);
	ans = 0;
	swap(&a, &b);
	while(b > 0){
		c = a / b;
		ans = ans + c * b * 4;
		a = a - b * c;
		swap(&a,&b);
	}
	printf("%llu",ans);
	
}

void swap(long long int *a, long long int *b){
	long long int temp;
	if (*a < *b){
		temp = *a;
		*a = *b;
		*b = temp;
	}
}