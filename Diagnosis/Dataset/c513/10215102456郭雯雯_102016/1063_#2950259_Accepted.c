#include<stdio.h>

int main() {
	long long x, y, c = 0;	//数据太大要用长整型
	scanf("%lld %lld",&x,&y);
	while(x != 0 && y != 0) {
		long long k;
		if(x > y) {	//选择小的边来作为zzc的工作区域
			k = x/y;	//zzc在这次可以工作几次
			x = x%y;	//剩下的区域zzc这次做不了（太小了）
			c += k*y*4;
		}
		else {
			k = y/x;
			y = y%x;
			c += k*x*4; 
		}
	}
	printf("%lld\n",c);
} 
