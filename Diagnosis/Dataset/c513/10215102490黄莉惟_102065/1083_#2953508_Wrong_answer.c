#include <stdio.h>
#include<string.h>
#define LEN 1000
int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t ; i ++){
		int n, idx;
		scanf("%d",&n);
		int out[LEN] = {0};
		out[LEN - 1] = 1;
		for(int i = 0; i < n ; i ++){
			for(int k = LEN - 1; k > 1; k --){
				out[k] *=(i+1);
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
	
	return 0;
}