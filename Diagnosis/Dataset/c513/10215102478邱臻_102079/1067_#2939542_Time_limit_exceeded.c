#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
long long int tribonacci(long long int n){
	if(n==0)return 0;
	else if(n==1)return 1;
	else if(n==2)return 1;
	else return(tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3));  //递归 
}
int main() {
	long long int t,i,result,n;
	scanf("%lld",&t);
	for(i=0;i<t;i++){
		scanf("%lld",&n);  //n开始递归
		result=tribonacci(n); 
		printf("case #%lld:\n%lld\n",i,result);
	}
	return 0;
}