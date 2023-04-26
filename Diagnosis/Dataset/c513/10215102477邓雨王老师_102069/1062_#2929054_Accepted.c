#include <stdio.h>
typedef unsigned long long int llu;
llu map[51];
llu tribonacci(llu n)
{
	llu ret;
	if(n == 1){
		ret = 1;
		map[0] = ret;
	}else if(n == 2){
		ret = 2;
		map[1] = ret;
	}
	else if(n==3){
		ret=4;
		map[2]=ret;
	}
	else if(n==4){
		ret=8;
		map[3]=ret;
	}
	else{
		if(map[n-1] != 0){
			ret = map[n-1];
		}else{
			ret = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3) + tribonacci(n-4);
			map[n-1] = ret;
		}
}
	
	return ret;
}

int main(void)
{
	int t;
	scanf("%d", &t);
	int i; 
	for(i = 0 ; i < t; i ++){
		llu n, res;
		scanf("%llu", &n);
		res = tribonacci(n);
		printf("case #%d:\n", i);
		printf("%llu\n", res);
	}
}