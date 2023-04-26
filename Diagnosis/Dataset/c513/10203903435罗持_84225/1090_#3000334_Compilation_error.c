#include <stdio.h>
#define ll long long
#define N 10000
using namespace std;
ll n;
typedef struct{
	int cnt;
	int v[N];
}BIGINT;
BIGINT MUL(BIGINT a,BIGINT b){
	BIGINT R = {0,{0}};
	if(a.cnt==0 || b.cnt==0) return R;
	R.cnt = a.cnt+b.cnt;
	for(int i=0;i<b.cnt;i++){
		int t,k,j;
		int carry = 0;
		for(j=0;j<a.cnt;j++){
			t = a.v[j]*b.v[i]+carry+R.v[i+j];
			R.v[i+j] = t%10;
			carry = t/10;
		}
		k = i+j;
		while(carry>0){
			t = carry+R.v[k];
			R.v[k] = t%10;
			carry = t/10;
			k++;
		}
	}
	if(R.v[a.cnt+b.cnt-1]==0) R.cnt--;
	return R;
}
BIGINT mi(BIGINT a,ll n){
	BIGINT temp = a;
	BIGINT res = {1,{1}};
	while(n){
		if(n&1){
			res = MUL(res,temp);
			//res = res*temp;
		}
		temp = MUL(temp,temp);
		//temp = temp*temp;
		n >>= 1;
	}
	return res;
}
int main(void)
{
	while(scanf("%lld",&n)){
		if(n==0) break;
		ll num = n;
		BIGINT x = {0,{0}};
		while(num){
			x.v[x.cnt++] = num%10;
			num /= 10;
		}
		BIGINT R = mi(x,n);
		printf("%d\n",R.v[R.cnt-1]);
	}
	return 0;
}