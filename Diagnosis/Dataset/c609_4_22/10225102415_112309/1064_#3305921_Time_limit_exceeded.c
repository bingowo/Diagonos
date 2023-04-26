#include <stdio.h>

unsigned long long int solve(unsigned long long int x, unsigned long long int y) {
	if (x == y) return 4*x;
	unsigned long long int big = x>y ? x:y;
	unsigned long long int small = x<y ? x:y;
	return 4*small + solve(big-small, small);
}

int main() {
	unsigned long long int x, y;
	scanf("%lld %lld",&x, &y);
	printf("%lld", solve(x, y));
	return 0;
}