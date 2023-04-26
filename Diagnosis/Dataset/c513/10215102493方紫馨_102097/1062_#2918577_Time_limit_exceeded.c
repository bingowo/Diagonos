#include<stdio.h>
long long fib(int n){
	if(n==1)
		return 1;
	if(n==2)
		return 2;
	if(n==3)
		return 4;
	if(n==4)
		return 8;
	return fib(n-1)+fib(n-2)+fib(n-3)+fib(n-4);
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		int n;
		scanf("%d",&n);
		printf("case #%d:\n",i);
		printf("%lld\n",fib(n));
	}
	
}