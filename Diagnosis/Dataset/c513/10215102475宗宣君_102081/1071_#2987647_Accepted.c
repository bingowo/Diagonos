#include<stdio.h>
typedef long long ll;
const int N=1e6+5;
const ll p=1e4+7;
ll c[10000];
void factors() {//阶乘
	ll i;
	for(i = 0; i<10000; i++) {
		if(i<=1)
			c[i]=1;
		else
			c[i]=(c[i-1]%p)*i%p;
	}
}
ll binaryPow(ll a,ll b) {//快速幂
	ll ans=1;
	while(b>0) {
		if(b&1) {
			ans=ans*a%p;
		}
		a=a*a%p;
		b>>=1;
	}
	return ans;
}
ll comp(ll n,ll m) {//Lucas
	return c[n]*binaryPow(c[m]*c[n-m]%p,p-2)%p;
}

int main() {
	factors();
	int t;
	scanf("%d",&t);
	int i;
	for(i = 0; i < t; i++) {
		int a,b,k,n,m;
		scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
		ll ans=comp(k,n);
		ans=(ans%p)*(binaryPow(a,n)%p)%p;
		ans=(ans%p)*(binaryPow(b,m)%p)%p;
		printf("case #%d:\n%lld\n",i,ans);
	}
	return 0;
}

