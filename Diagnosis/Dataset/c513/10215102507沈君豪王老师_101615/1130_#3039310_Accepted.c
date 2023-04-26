#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef unsigned long long llu;
typedef long double ld;

int main(void)
{
	int t;
	scanf("%d", &t);
	while(t --){
		llu n;
		scanf("%llu", &n);
		if(n == 1 || n == 2){
			printf("%lld is powerless.", n);
		}else{
			llu n1 = n, n2 = 1;
			int isPower = 0, isExist = 0;
			printf("%llu", n1);
			int isFind = 0;
			for(int i = 2; i <= 64; i ++){
				llu anw = pow((ld)n,(ld)1.0/i)+0.5;
				llu res = 1;
				for(int j = 0 ; j < i; j ++){
					res *= anw;
				}
				if(res == n1){
					isFind = 1;
					printf("=%llu^%llu", anw, i);
				}
			}
			if(!isFind){
				printf(" is powerless.");
			}
		}
		printf("\n");
	}
	
	return 0;
}