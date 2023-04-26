#include <stdio.h>
#define ll long long
int T;
ll a,b,n;
ll ksm(ll a,ll b,ll n){
	ll mod = 1;
	for(int i=1;i<=n;i++) mod *= 10;
	ll temp = a%mod, res = 1;
	while(b){
		if(b&1) res = (res*temp)%mod;
		temp = (temp*temp)%mod;
		b >>= 1;
	}
	return res%mod;
}
int main(void)
{
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++){
		scanf("%lld %lld %lld",&a,&b,&n);
		printf("case #%d:\n",kase);
		int ans[20] = {0};
		ll aans = ksm(a,b,n);
		int idx = 0;
		while(aans){
			ans[idx++] = aans%10;
			aans /= 10;
		}
		for(int i=n-1;i>=0;i--) printf("%d",ans[i]);
		putchar('\n');
	}
	return 0;
}