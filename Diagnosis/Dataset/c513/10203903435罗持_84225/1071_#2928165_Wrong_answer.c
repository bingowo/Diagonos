#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
long long dp[1010][1010] = {0};
const long long MOD = 10007;
int T;
long long ksm(long long a,long long k){
	long long res = 1, temp = a;
	while(k){
		if(k&1) res = (res%MOD)*(temp%MOD);
		temp = (temp%MOD) * (temp%MOD);
		k >>= 1;
	}
	return res%MOD;
}
int main(void)
{
	for(int i=1;i<=1000;i++){
		for(int j=0;j<=i;j++){
			if(j==0 || i==j) dp[i][j] = 1;
			else dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%MOD;
		}
	}
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++){
		long long a,b,k,n,m;
		scanf("%lld %lld %lld %lld %lld",&a,&b,&k,&n,&m);
		if(a==0 && b==0){
			printf("0\n");
			continue;
		}
		long long ans = ((dp[k][m]%MOD) * ksm(a,n) * ksm(b,m))%MOD;
		printf("case #%d:\n",kase);
		if(ans==0) ans++;
		printf("%lld\n",ans);
	}
	return 0;
}