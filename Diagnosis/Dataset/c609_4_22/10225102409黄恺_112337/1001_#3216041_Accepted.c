#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	int i = 0; 
	for (; i < T; i++) {
		long long N;
		int R;
		scanf("%lld %d", &N, &R);
		int sign = 1;
		if (N < 0) {
			N = -N;
			sign = -1;
		}
		char num[100] = {0};
		int n = 0;
		while (N > 0) {
			int number = N % R;
			if (number > 9) {
				number = number - 10 +'A';
			} else {
				number = number + 48;
			}
			num[n] = number;
			N = N / R;
			n++;
		}
		if (sign == -1) {
			printf("-");
		}
		for (n--; n >= 0; n--) {
			printf("%c", num[n]);
		}
		printf("\n");
		
		
	}
	
	return 0;
} 