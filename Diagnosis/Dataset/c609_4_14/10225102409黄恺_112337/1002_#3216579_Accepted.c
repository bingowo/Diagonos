#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	int i = 0;
	while (i<T) {
		int n;
		scanf("%d", &n);
		int ans[100];
		int idx = 0;
		while(n) {
			ans[idx++] = n % 2;
			n /= 2;
		}
		idx--;
		int max = 1;
		int temp = 1;
		while(idx) {
			if (ans[idx] != ans[idx-1]) {
				temp += 1;
				idx--;
				if (temp > max) {
					max = temp;
				}
			} else {
				temp = 1;
				idx--;
			}	
		}
		printf("case #%d:\n%d\n", i, max);
		i++;
	}
	
	return 0;
} 