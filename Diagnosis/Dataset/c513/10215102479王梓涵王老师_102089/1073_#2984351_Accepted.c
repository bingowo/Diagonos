#include <stdio.h>
#include <string.h>

typedef unsigned long long int lli;
lli dp[20][180][2];
//得到数字 
lli GetDigit(lli x, lli d[])
{
	int index = 0;
	while(x){
		d[index ++] = x % 10;
		x /= 10;
	}
	return index;
}

lli CountMiao(int idx/*给的数字的index*/, int sum/*数位和*/, int limit/*限制，是0~k还是0~9*/, lli d[])
{
	if(idx == -1){
		//数位和被9整除不妙 
		if(sum % 9 == 0){
			return 0;
		}else{
			return 1;
		}
	}
	//判断是否已经算过了 
	if(dp[idx][sum][limit] != -1 && limit != 1){
		return dp[idx][sum][limit];
	}
	lli ret = 0;	//返回妙数的个数 
	int k = (limit) ? d[idx] : 9;
	for(int i = 0 ; i <= k ; i ++){
		if(i != 9){
			//判断下一个状态是否要限制数位和 
			int newLimit = (d[idx] == i) ? limit : 0; 
			ret += CountMiao(idx - 1/*往低位移动一位*/, sum + i/*加上数位和*/, newLimit, d);			
		}
	}
	//存储一个最终的状态。如果不设置limit，那么就会有许多不必要的中间态被存储 
	if(!limit){
		dp[idx][sum][limit] = ret;
	}
	
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