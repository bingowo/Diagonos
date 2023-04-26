#include<stdio.h>
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
		ret+=4*min;
		max-=min;
		if(min>max){
			int temp = max;
			max = min;
			min = temp;
		}
	}
	printf("%llu", ret);
	return 0;
}