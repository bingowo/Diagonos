/*
Created by Shizumu on 2022-03-14
	这个题考自己的知识够不够，如果你知道怎么快速算组合数取模，那就好办了 。
	不知道……那有点麻烦了。你可能需要知道“逆元”和“Lucas定理”，否则应
该会遇到一些麻烦。 
*/ 
#include <stdio.h>
#include <math.h>

typedef unsigned long long int llu;
const int p = 10007;

//计算 a^b (mod p) 
llu mod(int a, int b)
{
	llu ret = 1;
	a %= p;
	while(b){
		if(b & 1){
			ret = (ret * a) % p;
			b --;
		}
		a = (a * a) % p;
		b >>= 1;
	}

	return ret;
} 

//计算组合数C(k,n) 
llu combination(int k, int n)
{
	if(n > k){
		return 0;
	}
	if(n > k - n){
		n = k - n;
	}
	llu ret = 1;
	llu inverse;
	for(int i = 1; i <= n ; i ++){
		ret = (ret * (k + 1 - i)) % p;
		//这里计算了逆元，用到了费马小定理计算。 
		inverse = mod(i, p - 2);
		ret = (inverse * ret) % p;
	}
	
	
	return ret;
}
//Lucas定理的具体实现 
llu Lucas(int k, int n)
{
	if(n == 0){
		return 1;
	}else{
		return combination(k % p, n % p) * Lucas(k / p, n / p) % p;
	}
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t; i ++){
		int a, b, k, n, m;
		scanf("%d %d %d %d %d", &a, &b, &k, &n, &m);
		llu res = (Lucas(k, n) * mod(a, n) * mod(b, m) ) % 10007;		
		printf("case #%d:\n", i);
		printf("%lld\n", res);
	}
	
	return 0;
}
