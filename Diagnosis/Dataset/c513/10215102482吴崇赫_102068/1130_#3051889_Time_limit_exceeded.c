#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define N 105

int GCD(int _m, int _n) {  // m > n
	int m = _m > _n ? _m : _n;
	int n = _m < _n ? _m : _n;
	return m % n == 0 ? n : GCD(n, m % n);
}

long long qpow(long long a, long long n) {
	if (n == 0) return 1;
	else if (n % 2) return a * qpow(a, n - 1);
	else{
		long long temp = qpow(a, n / 2);
		return temp * temp;
	}
}

int canDisplay(long long num, long long base) {
	if (num == 1) return -1;
	long long top = num / base;
	for (int i = 2; i <= top; ++i) {
		if (qpow(base, i) == num) return i;
	}
	return -1;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		long long n;
		scanf("%lld", &n);
		long long base = n / 2;
		printf("%lld", n);
		int flag = 0;
		while (base > 1) {
			int c = canDisplay(n, base);
			if (c > 1) {
				flag = 1;
				printf("=%lld^%d", base, c);
			}
			//printf("%d ", flag);
			base--;
		}
		//printf("%d",flag);
		if (flag == 0)printf(" is powerless.");
		printf("\n");
	}
	return 0;
}