#include <stdio.h>

typedef long long ll;

ll fun(ll n, ll m){
 ll ans = 1;
    ll i;
    for(i = 1; i <= m; i++){
     ans = ans * (n - m + i) / i;
    }
    return ans;
}

int main(){
 int T;
 scanf("%d",&T);
 int i;
 for(i = 0; i < T; i++){
  ll num1, num2;
  scanf("%lld%lld",&num1, &num2);
  ll res = fun(num1, num2);
  printf("case #%d:\n",i);
  printf("%lld\n",res);
 }
 return 0;
}