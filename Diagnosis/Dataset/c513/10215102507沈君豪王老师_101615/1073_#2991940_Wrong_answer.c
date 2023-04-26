#include <stdio.h>
#include <string.h>

typedef unsigned long long int lli;

lli dp[20][180][2];
// ²ÎÊý£ºidx sum limitÓëCountMiao()¶ÔÓ¦
 

lli GetDigit(lli x, lli d[])
{
	int index = 0;
	while(x){
		d[index ++] = x % 10;
		x /= 10;
	}
	return index;
}

lli CountMiao(int idx, int sum, int limit, lli d[])
{
	if(idx == -1){
		if(sum % 9 == 0){
			return 0;
		}else{
			return 1;
		}
	}
	if(dp[idx][sum][limit] != -1){
		return dp[idx][sum][limit];
	}
	lli ret = 0;
	int k = (limit) ? d[idx] : 9;
	for(int i = 0 ; i <= k ; i ++){
		if(i != 9){
			int newLimit = (d[idx] == i) ? limit : 0;
			ret += CountMiao(idx - 1, sum + i, newLimit, d);			
		}
	}
	dp[idx][sum][limit] = ret;
	
	return ret;
}

int main(void)
{
	lli a, b;
	scanf("%lld %lld", &a, &b);
	lli digitA[20], digitB[20];
	int lena, lenb;
	memset(dp, -1, sizeof(dp));
	lena = GetDigit(a - 1, digitA), lenb = GetDigit(b, digitB);
	lli resa = CountMiao(lena - 1, 0, 1, digitA);
	lli resb = CountMiao(lenb - 1, 0, 1, digitB);
	printf("%llu", resb - resa);
	
	return 0;
}