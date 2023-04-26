#include<stdio.h>
long long rev(long long a){
	long long sum=0;
	long long temp=a;
	while(temp>0){
		sum=sum*10+temp%10;
		temp/=10;
	}
	return sum;
}
int pd(long long a){
	if(a==rev(a)) return 1;
	else return 0;
}
int main(){
	long long x;
	int count=0;
	scanf("%lld",&x);
	while(pd(x)==0){
		x=x+rev(x);
		count++;
	}
	printf("%d %lld",count,x);
}