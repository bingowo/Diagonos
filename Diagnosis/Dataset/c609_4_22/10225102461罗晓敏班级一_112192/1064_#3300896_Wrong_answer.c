#include <stdio.h>
long long int ret=0;
void f(long long int a,long long int b){
	if(a>b){
		ret+=4*b;
		f(a-b,b);
	}else if(b>a){
		ret+=4*a;
		f(a,b-a);
	}else{
		ret+=4*a;
		return; 
	}
}
int main(){
	long long int x,y;scanf("%lld%lld",&x,&y);
	if(x>y){
	    if(x%y){
	        f(x,y);
	    }else{
	        4*y*(x%y);
	    }
	}else if(x<y){
	    if(y%x){
	        f(x,y);
	    }else{
	        4*x*(y%x);
	    }
	}else{
	    ret=4*x;
	}
	
	printf("%lld",ret);
}