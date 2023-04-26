#include<stdio.h>
int cal(long long a){    //判断a中是否有9 
	while(a>0){
		if(a%10==9){
			return 1;
			break;
		}
		else a=a/10;
	}
	return 0; 
}
int main(){
	long long a,b;
	scanf("%lld%lld",&a,&b);
	long long i;
	long long count=0;
	for(i=a;i<=b;i++){
		if(i%9==0||cal(i)==1){
			count++;
		}
	}
	printf("%lld",b-a+1-count);
}