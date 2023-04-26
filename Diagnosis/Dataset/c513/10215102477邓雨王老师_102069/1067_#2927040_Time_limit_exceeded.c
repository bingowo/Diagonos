#include<stdio.h>
long long fib(long long n){
	if(n==0) return 0;
	else if(n==1||n==2) return 1;
	else return fib(n-1)+fib(n-2);
}
int main(){
	int m;
	scanf("%d",&m);
	int i;
	for(i=0;i<m;i++){
		int n;
		scanf("%d",&n);
		printf("case #%d:\n",i);
		printf("%lld\n",fib(n));
	}
}