#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
long long  GCD(long long x,long long y){
	long long r;
	if(x%y==0) return y;
	else {
		r=x%y;
		GCD(y,r);
	}
} 
void step1(long long a,long long b){
	long long  In=a/b;//整数部分 
	long long N=A-In*B; //分子部分
	long long zi,mu;
	long long r=GCD(N,B);
	zi=N/r,mu=B/r; 
}
int main(){
	long long A,B;
	scanf("%lld %lld",&A,&B);
	
	return 0;
}
