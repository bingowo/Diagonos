#include <stdio.h>

int f(int x, int y) {
	int z = x ^ y;
	int num = 0;
	do {
		if (z % 2)
			num++;
		z /= 2;
	} while (z > 0);
	return num;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", f(x, y));
	}
	return 0;
}
