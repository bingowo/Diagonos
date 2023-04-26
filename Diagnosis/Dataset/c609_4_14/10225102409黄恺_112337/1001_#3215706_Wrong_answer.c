#include <stdio.h>

int main() {
	int T;
	scanf("%d\n", &T);
	int i = 0; 
	for (; i < T; i++) {
		long long N;
		int R;
		scanf("%lld %d\n", &N, &R);
		int num[100] = {0};
		int n = 0;
		while (N > 0) {
			int number = N % R;
			num[n] = number;
			N = N / R;
			n++;
		}
		for (; n >= 0; n--) {
			printf("%d", num[n]);
		}
		printf("\n");
		
		
	}
	
	return 0;
} 