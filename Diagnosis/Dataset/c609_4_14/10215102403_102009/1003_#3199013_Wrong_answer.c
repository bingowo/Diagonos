#include<stdio.h>
int main(){
	int t;
	scanf("%d\n",&t);
	while(t>0){
		long long int a[15],i=0;
		long long int n;
		scanf("%lld\n",&n);
		while(n){
			a[i]=n%2333;
			n/=2333; i++;
		} i--;
		if(n==0) printf("0");
		while(i>=0){
			printf("%lld ",a[i]); i--; 
		}
		printf("\n");
		t--;
	}
	return 0;
} 