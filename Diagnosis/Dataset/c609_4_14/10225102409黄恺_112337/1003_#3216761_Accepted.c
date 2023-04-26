#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	int i = 0; 
	for (; i < T; i++) {
		long long N;
		int R = 2333;
		scanf("%lld", &N);
		if (N == 0) {
			printf("0");
		} else{
			int num[100] = {0};
			int n = 0;
			while (N > 0) {
				int number = N % R;
	
				num[n++] = number;
				N = N / R;
			}
	
			for (n--; n >= 0; n--) {
				printf("%d ", num[n]);
			}
		}
		
		printf("\n");
		
		
	}
	
	return 0;
} 