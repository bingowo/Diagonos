#include<stdio.h>
#include<string.h>
#define Maxn 1010
const int mod = 10007;
int c[Maxn], a, b, k, n, m;
int pow_c(int x, int num){
	int res = 1 % mod;
	x %= mod;
	while(num){
		if(num & 1) res = (res * x) % mod;
		x = (x * x) % mod;
		num >>= 1;
	}
	return res;
}
int main(){
	int t, a, b, k, n, m, i, j;
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		scanf("%d %d %d %d %d", &a, &b, &k, &n, &m);
		memset(c, 0, sizeof(c));
		c[0] = 1;
		for(j = 1; j <= k; j++) c[j] = c[j - 1] * j % mod;
		int ans = c[k] * pow_c(c[m] * c[k - m], mod - 2) % mod;
		printf("case #%d:\n%d\n", i, ans * pow_c(b, k - n) % mod * pow_c(a, n) % mod);
	}
	return 0;
}