#include<stdio.h>
#include<string.h>
#include <stdlib.h>
long long int reverse(long long int n){
    long long int sum = 0;
	while(n > 0){
		sum = sum * 10 + n % 10;
		n /= 10;
	}
	return sum;
}
int main(){
    long long int n;
    long long int num=0;
    scanf("%lld",&n);
    long long int m;
    while((m=reverse(n))!=n){
        n=m+n;
        num++;
    }
    printf("%lld %lld",num,m);
}