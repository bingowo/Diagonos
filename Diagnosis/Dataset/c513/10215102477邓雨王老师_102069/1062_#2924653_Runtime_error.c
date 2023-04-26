#include<stdio.h>
long long recursion(long long n){
	if(n==1){
		return 1;
	}
	else if(n==2){
		return 2;
	}
	else if(n==3){
		return 4;
	}
	else if(n==4){
		return 8;
	}
	return recursion(n-1)+recursion(n-2)+recursion(n-3)+recursion(n-4);
}
int main(){
	int chance;
	scanf("%d\n",chance);
	int i;
	for(i=0;i<chance;i++){
		long long m;
		scanf("%lld",&m);
		long long sum=recursion(m);
		printf("case #%d:\n",i);
		printf("%lld\n",sum);
	}
}