#include<stdio.h>
long long step(int n){
	if(n==1){
		return 1;
	}else if(n==2){
		return 2;
	}else if(n==3){
		return 4;
	}else if(n==4){
		return 8;
	}else{
		return step(n-4)+step(n-3)+step(n-2)+step(n-1);
	}
}
int main(){
	int t,i;scanf("%d",&t);
	for(i=0;i<t;i++){
		int n;scanf("%d",&n);
		printf("%lld",step(n));
	}
}