#include<stdio.h>
int main(){
	int x, y;
	scanf("%d %d", &x, &y);
	int min = x;
	int max = y;
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
		ret+=4*min;
		max-=min;
		if(min>max){
			int temp = max;
			max = min;
			min = temp;
		}
	}
	printf("%lld", ret);
	return 0;
}