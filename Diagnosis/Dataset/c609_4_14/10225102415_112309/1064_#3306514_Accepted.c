#include <stdio.h>

unsigned long long int solve(unsigned long long int x, unsigned long long int y) {
// 	if (x == y) return 4*x;
// 	unsigned long long int big = x>y ? x:y;
// 	unsigned long long int small = x<y ? x:y;
// 	return 4*small + solve(big-small, small);
    unsigned long long int a, b, ret;
    while(y) {
        a = x / y;
        b = x % y;
        ret += 4*a*y;
        x = y;
        y = b;
    }
    return ret;
}

int main() {
	unsigned long long int x, y;
	scanf("%lld %lld",&x, &y);
	printf("%lld", solve(x, y));
	return 0;
}
