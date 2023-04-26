/*
	Created by Shizumu on 2022-03-21
	这个不需要计算出大数，所以没什么难点 
*/
#include <stdio.h>
typedef long long int lli;

lli fpow(lli a, lli b, lli m)
{
	if(b == 0){
		return 1;
	}else if(b == 1){
		return a % m;
	}else{
		a %= m;
		if(b % 2 == 0){
			lli temp = (fpow(a, b / 2, m) % m); 
			return (temp * temp) % m;
		}else{
			return ((fpow(a, b - 1, m) % m) * (a % m)) % m;
		}
	}
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t; i ++){
		lli a, b, n;
		scanf("%lld %lld %lld", &a, &b, &n);
		lli multi = 1;
		for(int i = 0 ; i < n; i ++){
			multi *= 10;
		}
		printf("case #%d:\n", i);
		//这里控制格式利用了'*'，表示格式控制中使用一个整数变量 
		printf("%0*lld\n", n/*控制有几个零*/, fpow(a, b, multi));
	}
	
	return 0;
}
