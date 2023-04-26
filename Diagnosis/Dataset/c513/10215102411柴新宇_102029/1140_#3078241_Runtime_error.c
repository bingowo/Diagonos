#include <stdio.h>

int main() {
	long long int n;
	scanf("%lld", &n);
	long long int a[11111] = {0};
	long long int b[11111] = {0};
	for (long long int i = 0; i < n; i++) {
		long long int num, thing;
		scanf("%lld", &num);
		for (long long int j = 0; j < num; j++) {
			scanf("%lld", &thing);
			if (thing >= 0)
				a[thing]++;
			else {
				thing = -thing;
				b[thing]++;
			}
		}
	}
	for (long long int k = 11111; k > 0; k--) {
		if (b[k] == n)
			printf("%lld ", -k);
	}
	for (long long int k = 0; k < 11111; k++) {
		if (a[k] == n)
			printf("%lld ", k);
	}


	return 0;
}
