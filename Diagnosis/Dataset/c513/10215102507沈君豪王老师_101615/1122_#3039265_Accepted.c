#include <stdio.h>

typedef long long int lli;

int main(void)
{
	int t;
	scanf("%d", &t);
	while(t --){
		lli n;
		scanf("%lld", &n);
		lli res[100] = {0, }, idx = 0;
		if(n == 0){
			printf("0\n");
		}else{
			while(n){
				res[idx ++] = n % 2333;
				n /= 2333;
			}
			idx --;
			for(; idx >= 0; idx --){
				printf("%lld ", res[idx]);
			}
			printf("\n");			
		}
	}
	
	return 0;
}