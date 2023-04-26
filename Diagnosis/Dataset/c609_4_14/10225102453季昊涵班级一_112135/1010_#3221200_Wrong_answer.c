#include <stdio.h>
#include <stdlib.h>

void f(int n, int r, int pr) {
	if (!n && !pr)
		return ;
	int num = n % r + pr;
	pr = 0;
	if (num < 0) {
		num = num - r;
		pr = 1;
	}
	if (num == -r) {
		num = 0;
		pr = -1;
	}
	f(n / r, r, pr);
	printf("%X", num);
}

int main() {
	int n, r;
	scanf("%d %d", &n, &r);
	f(n, r, 0);
	return 0;
}