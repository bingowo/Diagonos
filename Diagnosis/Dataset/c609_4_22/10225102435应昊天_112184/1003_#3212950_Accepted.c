#include<stdio.h>
#include<string.h> 
void trans(long long n);
int main(){
	int T;
	scanf("%d",&T);
	long long n;
	int index = 0;
	for(int i = 0;i < T;i++){
		scanf("%lld",&n);
		if(n == 0)
			printf("%d",0);
		else{
			trans(n);
		}
		printf("\n");
	}
	return 0;	
}
void trans(long long n){
	if(n > 0){
		trans(n/2333);
		printf("%d",n % 2333);
		putchar(' ');
	}
}