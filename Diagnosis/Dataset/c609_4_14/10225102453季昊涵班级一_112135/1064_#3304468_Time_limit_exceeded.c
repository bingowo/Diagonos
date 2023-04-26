#include <stdio.h>

long long int solve(long long int a, long long int b) {
	if (a == b) {
		return 4 * a;
	} else if (a > b) {
		return b * 4 + solve(a - b, b);
	} else {
		return a * 4 + solve(b - a, a);
	}
}

int main() {
	long long int x, y;
	scanf("%lld %lld", &x, &y);
	printf("%lld", solve(x, y));
}