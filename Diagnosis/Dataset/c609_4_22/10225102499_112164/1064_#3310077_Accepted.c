#include<stdio.h>
int main(){
	long long x,y,r=0;
	scanf("%lld %lld",&x,&y);
	while(x&&y){ 
		if(x>y){
			r+=4*(x/y)*y;
			x%=y;
		}else{
			r+=4*(y/x)*x;
			y%=x;	
		}
	}
	printf("%lld",r);
	return 0;
}