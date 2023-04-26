#include<stdio.h>
typedef long long LL;
const int mod = 10007;
int a, b, k, n, m;
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
	scanf("%d %d %d %d %d", &a, &b, &k, &n, &m);
	int c[1010];
	c[1] = 1;
	for (int i = 2; i <= k; i++) c[i] = c[i - 1] * i % mod;
	int ans = c[k] * pow_c(c[m] * c[k - m], mod - 2) % mod;
	printf("%d\n", ans * pow_c(b, k - n) % mod * pow_c(a, n) % mod);
	return 0;
}