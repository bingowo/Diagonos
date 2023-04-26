#include<stdio.h>
int main(){
    long long x, y;
	scanf("%lld %lld", &x, &y);
	long long min = x;
	long long max = y;
    long long ret = 0;
	if(y<x){
		min = y;
		max = x;
	}
	while(min>0&&max>0){
	    if(min>max){int temp = max;max=min;min=temp;}
		if(min==max){
			ret+=4*min;
			break;
		}
		if(max%min==0){
		    ret+=(4*min)*(max/min);
		    break;
		}
		ret+=max/min*min*4;
		long long temp = min;
		min = max%min;
		max = temp;
	}
	printf("%lld", ret);
	return 0;
}