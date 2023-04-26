#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define LEN 1000
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        long long int A,B,N;
        scanf("%lld %lld %lld",&A,&B,&N);
        long long int out[LEN] = {0};
		out[LEN - 1] = 1;
		for(int i = 0; i < B ; i ++){
			for(int k = LEN - 1; k > 1; k --){
				out[k] *= A;
			}
			for(int k = LEN - 1, carry; k > 1; k --){
				carry = out[k] / 10;
				out[k] %= 10;
				out[k - 1] += carry;
			}
		}
			printf("case #%d:\n", i);
		for(idx = 0; out[idx] == 0; idx ++);
		for(; idx < LEN; idx ++){
			printf("%d", out[idx]);
		}
		printf("\n");
    }
}