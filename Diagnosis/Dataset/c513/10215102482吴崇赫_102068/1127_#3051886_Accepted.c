#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define N 105

typedef struct {
	int top;
	int bottom;
}fraction;

int GCD(int _m, int _n) {  // m > n
	int m = _m > _n ? _m : _n;
	int n = _m < _n ? _m : _n;
	return m % n == 0 ? n : GCD(n, m % n);
}

void simpleFaction(fraction* f) {
	int zi = f->top;
	int mu = f->bottom;
	f->bottom = mu / GCD(zi, mu);
	f->top = zi / GCD(zi, mu);
}

void fractionAdd(fraction* sum, fraction* add) {
	int a = sum->bottom, b = sum->top;
	int c = add->bottom, d = add->top;
	sum->bottom = a * c;
	sum->top = b * c + a * d;
	simpleFaction(sum);
}

int main() {
	int frac_num;
	scanf("%d", &frac_num);
	fraction f[N], sum;
	for (int i = 0; i < frac_num; ++i) {
		scanf("%d/%d", &f[i].top, &f[i].bottom);
	}
	sum.bottom = f[0].bottom;
	sum.top = f[0].top;
	for (int i = 1; i < frac_num; ++i) {
		fractionAdd(&sum, &f[i]);
	}
	printf("%d/%d", sum.top, sum.bottom);
	return 0;
}