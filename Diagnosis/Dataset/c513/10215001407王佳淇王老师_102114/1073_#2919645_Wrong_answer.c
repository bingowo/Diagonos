#include<stdio.h>
int digit9(long long int n){
	int s[23],v=0;
	for(;n;v++){
		s[v]=n%10;
		n/=10;
	}
	for(int l=0;l<v;l++){
		if(s[l]==9) return 1;
	}
	return 0; 
}
int divise9(long long int n){
	if(n%9==0) return 1;
	else return 0;
}
int main(){
	long long int a,b,i,count;
	scanf("%lld %lld\n",&a,&b);
	for( i=a;i<=b;i++){
		int j=digit9(i);
		int k=divise9(i);
		if(j==0&&k==0) count++;
	}
	printf("%lld",count);
	return 0;
}