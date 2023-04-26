#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define mod 10007
int pow_c(int x, int num){
	int res = 1 % mod;
	x %= mod;
	while(num){
		if(num & 1) res = (res * x) % mod;
		x = (x * x) % mod;
		num >>= 1;
	}
	return res;
}//快速幂解法
int c[1000005];
int main()
{
    int T;
    scanf("%d",&T);
    int a,b,k,n,m;
    for(int cas=0;cas<T;cas++)
    {
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        c[1] = 1;
        printf("case #%d:\n",cas);
        for (int i = 2; i <= k; i++) c[i] = c[i - 1] * i % mod;
        int ans = c[k] * pow_c(c[m] * c[k - m], mod - 2) % mod;
        printf("%d\n", ans * pow_c(b, k - n) % mod * pow_c(a, n) % mod);
    }
    return 0;
}
