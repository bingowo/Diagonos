#include<stdio.h>
int digit9(unsigned long long int n){
	int s,v=0;
	for(;n;v++){
		s=n%10;
		n/=10;
		if(s==9) return 1;
	}
	return 0; 
}
int divise9(unsigned long long int n){
	if(n%9==0) return 1;
	else return 0;
}
int main(){
	long long int a,b,i,count;
	scanf("%llu %llu\n",&a,&b);
	for( i=a;i<=b;i++){
		int j=digit9(i);
		int k=divise9(i);
		if(j==0&&k==0) count++;
	}
	printf("%llu",count);
	return 0;
}