#include <stdio.h>
#include <string.h>
#define LEN 600

typedef struct{
	int num[LEN];
	int sgn;	//ÎÞ·ûºÅÇé¿öÏÂ¿ÉÒÔÊ¡ÂÔ
}BigInt;

BigInt stobi(char s[])
{
	char *p = NULL;
	BigInt bn;
	memset(&bn, 0, sizeof(bn));
	int idx = LEN - 1;
	bn.sgn = 1;
	for(p = s; *p; p ++);
	while(1){
		p --;
		if(*p != '-'){
			bn.num[idx --] = *p - '0';
		}
		if(p == s || *p == '-'){
			if(*p == '-'){ bn.sgn = -1;}
			break;
		}
	}
	
	return bn;
}

int BigIntcmp(BigInt a, BigInt b)
{
	int ret = 0;
	if(a.sgn == 1 && b.sgn == -1){
		ret = 1;
	}else if(a.sgn == -1 && b.sgn == 1){
		ret = -1;
	}else{
		for(int i = 0 ; i < LEN ; i ++){
			if(a.num[i] > b.num[i]){
				ret = 1;
				break;
			}else if(a.num[i] < b.num[i]){
				ret = -1;
				break;
			}
		}
		if(ret != 0){ret *= a.sgn; }
	}
	
	return ret;
}

BigInt sub(BigInt a, BigInt b)
{
	BigInt ret;
	memset(&ret, 0, sizeof(ret));
	int c;
	if((c = BigIntcmp(a, b)) == 1){
		for(int i = LEN - 1; i ; i --){
			ret.num[i] = ret.num[i] + a.num[i] - b.num[i];
			if(ret.num[i] < 0){
				ret.num[i] += 10;
				ret.num[i - 1] -= 1;
			}
		}
		ret.sgn = 1;
	}else if(c == -1){
		ret = sub(b ,a);
		ret.sgn = -1;
	}else{
		memset(&ret, 0, sizeof(ret));
		ret.sgn = 1;
	}
	
	return ret;
}

void PrintBigInt(BigInt bn)
{
	if(bn.sgn == -1){printf("-");}
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
	char s1[LEN], s2[LEN];
	while(scanf("%s %s", s1, s2) != EOF){
		BigInt a, b;
		a = stobi(s1), b = stobi(s2);
		if(BigIntcmp(a, b) == 0){
			printf("0\n");
		}else{
			PrintBigInt(sub(a, b)), printf("\n");
		}		
	}
	
	return 0;
}