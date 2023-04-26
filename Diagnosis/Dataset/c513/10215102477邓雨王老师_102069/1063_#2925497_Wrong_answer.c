#include<stdio.h>
int main(){
	long long x,y;
	scanf("%lld %lld",&x,&y);
	long long sum=0;
	long long gs;
	if(x%y==0){
		gs=x/y;
		sum=4*y*(x/y);
	}
	printf("%lld",sum);
}