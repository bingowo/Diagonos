#include<stdio.h>
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
		ret+=max/min*min*4;
		int temp = min;
		min = max%min;
		max = temp;
	}
	printf("%lld", ret);
	return 0;
}