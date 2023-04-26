#include <stdio.h>

typedef unsigned long long int llu;
llu map[75];

llu tribonacci(llu n)
{
	llu ret;
	if(n == 0){
		ret = 0;
		map[0] = ret;
	}else if(n == 1 || n == 2){
		ret = 1;
		map[1] = map[2] = 1;
	}else{
		if(map[n] != 0){
			ret = map[n];
		}else{
			ret = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
			map[n] = ret;
		}
	}
	
	return ret;
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t; i ++){
		llu n, res;
		scanf("%llu", &n);
		res = tribonacci(n);
		printf("case #%d:\n", i);
		printf("%llu\n", res);
	}
}