#include <stdio.h>
#include <math.h>

typedef unsigned long long int llu;
const int p = 10007;

//º∆À„ a^b (mod p) 
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

//º∆À„◊È∫œ ˝C(k,n) 
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
		//’‚¿Ôº∆À„¡ÀƒÊ‘™£¨”√µΩ¡À∑—¬Ì–°∂®¿Ìº∆À„°£ 
		inverse = mod(i, p - 2);
		ret = (inverse * ret) % p;
	}
	
	
	return ret;
}
//Lucas∂®¿ÌµƒæﬂÃÂ µœ÷ 
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
