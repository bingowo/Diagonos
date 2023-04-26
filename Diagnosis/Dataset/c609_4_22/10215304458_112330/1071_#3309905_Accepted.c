#include<math.h>
#include<stdio.h>
typedef long long ll;
ll solve(ll x,ll y){
	ll s=llabs(x)+llabs(y),c=log2(s)+1;
	if(!s) return 0;
	else if(!(s%2)) return -1;
	else return c;
}
int main(){
	ll x,y;
	scanf("%lld%lld",&x,&y);
	printf("%lld",solve(x,y));
	return 0;
} 