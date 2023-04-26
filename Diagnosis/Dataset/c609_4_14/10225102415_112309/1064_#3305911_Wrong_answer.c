#include <stdio.h>

long long int solve(long long int x, long long int y) {
	if (x == y) return 4*x;
	long long int big = x>y ? x:y;
	long long int small = x<y ? x:y;
	return 4*small + solve(big-small, small);
}

int main() {
	long long int x, y;
	scanf("%d %d",&x, &y);
	printf("%d", solve(x, y));
	return 0;
}