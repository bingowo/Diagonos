#include <stdio.h>
#include <string.h>
#define LEN 200
typedef struct{
	int num[LEN];
}BigInt;

BigInt map[501];
int isRecord[501];

BigInt add(BigInt a, BigInt b)
{
	BigInt ret;
	memset(&ret, 0, sizeof(ret));
	for(int i = LEN - 1; i ; i --){
		ret.num[i] = ret.num[i] + a.num[i] + b.num[i];
		if(ret.num[i] >= 10){
			ret.num[i] %= 10;
			ret.num[i - 1] += 1;
		}
	}
	return ret;
}

BigInt itobi(int n)
{
	BigInt bn;
	memset(&bn, 0, sizeof(bn));
	int idx = LEN - 1;
	while(n){
		bn.num[idx--] = n % 10;
		n /= 10;
	}
	return bn;
}

void init()
{
	for(int i = 0 ; i <= 500; i ++){
		map[i] = itobi(0);
	}
}

BigInt solve(int n)
{
	BigInt res;
	if(n == 1){
		map[1] = itobi(1);
		res = map[1];
		isRecord[1] = 1;
	}else if(n == 2){
		map[2] = itobi(2);
		res = map[2];
		isRecord[2] = 1;
	}else if(n == 3){
		map[3] = itobi(3);
		res = map[3];
		isRecord[3] = 1;
	}else if(n == 4){
		map[4] = itobi(6);
		res = map[4];
		isRecord[4] = 1;
	}else{
		if(isRecord[n]){
			res = map[n];	
		}else{
			res = add(add(solve(n - 1), solve(n - 2)), solve(n - 4));
			map[n] = res;
			isRecord[n] = 1;
		}
	}
	return res;
}

void PrintBigInt(BigInt bn)
{
	int idx;
	for(idx = 0 ; bn.num[idx] == 0 && idx < LEN ; idx ++);
	if(idx == LEN){
		printf("0");
	}else{
		for(; idx < LEN; idx ++){
			printf("%d", bn.num[idx]);
		}
	}
}


int main(void)
{
	int n;
	scanf("%d", &n);
	init();
	BigInt res = solve(n);
	PrintBigInt(res);
	
	return 0;
}