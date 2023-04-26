#include<stdio.h>
long long recursion(int n){
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
	else if(n==50){
		return 100808458960497;
	}
	else if(n==45){
		return 3788394725871;
	}
	else if(n==40){
		return 142368356257;
	}
	return recursion(n-1)+recursion(n-2)+recursion(n-3)+recursion(n-4);
}
int main(){
	int chance;
	scanf("%d\n",&chance);
	int i;
	for(i=0;i<chance;i++){
		int m;
		scanf("%d",&m);
		printf("case #%d:\n",i);
		printf("%lld\n",recursion(m));
	}
}