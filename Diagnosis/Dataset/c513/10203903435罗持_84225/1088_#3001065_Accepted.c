#include <stdio.h>
#define N 500
int T,m,n;
typedef struct{
	int cnt;
	int v[N];
}BIGINT;
BIGINT dp[50][50];
BIGINT BIGADD(BIGINT a,BIGINT b){
	BIGINT R = {0,{0}};
	if(a.cnt==0) return b; 
	if(b.cnt==0) return a;
	int i, carry = 0;
	for(i=0;i<a.cnt&&i<b.cnt;i++){
		int temp = a.v[i]+b.v[i]+carry;
		R.v[i] = temp%10;
		carry = temp/10;
	}
	while(i<a.cnt){
		int temp = carry+a.v[i];
		R.v[i++] = temp%10;
		carry = temp/10;
	}
	while(i<b.cnt){
		int temp = carry+b.v[i];
		R.v[i++] = temp%10;
		carry = temp/10;
	}
	if(carry) R.v[i++] = carry%10;
	R.cnt = i;
	return R;
}
int main(void)
{
	scanf("%d",&T);
	for(int i=1;i<=40;i++){
		BIGINT init = {1,{1}};
		dp[i][0] = init; 
	}
	for(int i=1;i<=40;i++){
		BIGINT init = {1,{1}};
		dp[i][i] = init; 
	}
	for(int i=2;i<=40;i++){
		for(int j=1;j<i;j++){
			dp[i][j] = BIGADD(dp[i-1][j],dp[i-1][j-1]);
		}
	}
	for(int kase=0;kase<T;kase++){
		scanf("%d %d",&n,&m);
		BIGINT R = dp[n][m];
		printf("case #%d:\n",kase);
		for(int i=R.cnt-1;i>=0;i--)
			printf("%d",R.v[i]);
		putchar('\n');
	}
	return 0;
}