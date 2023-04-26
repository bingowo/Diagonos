#include <stdio.h>

int solve(int x, int y) {
	if (x == y) return 4*x;
	int big = x>y ? x:y;
	int small = x<y ? x:y;
	return 4*small + solve(big-small, small);
}

int main() {
	int x, y;
	scanf("%d %d",&x, &y);
	printf("%d", solve(x, y));
	return 0;
}