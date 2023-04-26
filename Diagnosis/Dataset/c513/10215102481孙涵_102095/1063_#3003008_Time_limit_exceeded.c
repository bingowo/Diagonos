#include <stdlib.h>
#include <stdio.h>

void swap(long long int *a, long long int *b);

int main(){
	long long int a, b, c,ans;
	scanf("%lld",&a,&b);
	ans = 0;
	swap(&a, &b);
	while(b > 0){
		swap(&a, &b);
		c = a / b;
		ans = ans + c * b * 4;
		a = a - b * c;
	}
	printf("%lld",ans);
	
}

void swap(long long int *a, long long int *b){
	long long int *temp;
	if (*a < *b){
		temp = a;
		*a = *b;
		*b = *temp;
	}
}