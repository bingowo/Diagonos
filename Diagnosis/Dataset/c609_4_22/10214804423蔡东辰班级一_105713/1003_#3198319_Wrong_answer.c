#include <stdio.h>
int main(){
	int T, i = 0;
	int result[50] = {0};
	scanf("%d", &T);
	while(++i <= T){
		unsigned long long n;
		int cnt = 0;
		scanf("%llu", &n);
		while(n != 0){
			result[cnt++] = n % 2333;
			n /= 2333;
		}
		while(--cnt>=0){
			printf("%d ", result[cnt]);
		}
		printf("\n");
	}
	
	return 0;
}