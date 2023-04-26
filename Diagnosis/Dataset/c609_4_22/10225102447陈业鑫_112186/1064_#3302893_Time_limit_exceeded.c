#include<stdio.h>
unsigned long long int f(long long int x, long long int y){
    if(x<y){
        long long int temp = x;
        x = y;
        y = temp;
    }
    if(y==0)return 0;
    return (x/y)*4*y+f(y, x%y);
}
int main(){
	unsigned long long int x, y;
	scanf("%llu %llu", &x, &y);
	unsigned long long int min = x;
	unsigned long long int max = y;
	unsigned long long int ret = 0;
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
		ret = f(x, y);
	}
	printf("%llu", ret);
	return 0;
}