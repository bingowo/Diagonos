#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int a[11111] = {0};
	int b[11111] = {0};
	for (int i = 0; i < n; i++) {
		int num, thing;
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			scanf("%d", &thing);
			if (thing >= 0)
				a[thing]++;
			else {
				thing = -thing;
				b[thing]++;
			}
		}
	}
	for (int k = 11111; k > 0; k--) {
		if (b[k] == n)
			printf("%d ", -k);
	}
	for (int k = 0; k < 11111; k++) {
		if (a[k] == n)
			printf("%d ", k);
	}


	return 0;
}
