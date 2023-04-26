#include<stdio.h>
long long int f(long long int x, long long int y){
    if(x<y){
        long long int temp = x;
        x = y;
        y = temp;
    }
    if(y==0)return 0;
    return x/y*y*4+f(y, x%y);
}
int main(){
    long long int x, y;
	scanf("%lld %lld", &x, &y);
	long long int min = x;
	long long int max = y;
    long long int ret = 0;
	if(y<x){
		min = y;
		max = x;
	}
	while(min>0&&max>0){
		if(min==max){
			ret+=4*min;
			break;
		}
		if(max%min==0){
		    ret+=(4*min)*(max/min);
		    break;
		}
		ret = f(max, min);
	}
	printf("%lld", ret);
	return 0;
}