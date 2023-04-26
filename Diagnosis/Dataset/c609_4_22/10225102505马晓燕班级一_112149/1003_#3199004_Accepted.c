#include<stdio.h>
void trans(long long n){

	if(n>0){			
		trans(n/2333);
		printf("%lld ",n%2333);
	}
}
int main(){
	int t;
	long long n;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%lld",&n);
		
		if(n==0)
			putchar('0');
		else
			trans(n);
		printf("\n");
	}
	return 0;
}