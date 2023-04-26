#include<stdio.h>
long long dp[51]={0,1,1,1,1};
void f(long long n){
	long long i,j;
	for(i=1;i<=n;++i){
		for(j=1;j<=4;++j){
			dp[i+j]+=dp[i];
		}
	}
}
int main(){
	long long n,t,i;
	scanf("%lld",&t);
	f(50);
	for(i=0;i<t;++i){
		scanf("%lld",&n);
		printf("case #%lld:\n%lld\n",t,dp[n]);
	}
	return 0;
} 