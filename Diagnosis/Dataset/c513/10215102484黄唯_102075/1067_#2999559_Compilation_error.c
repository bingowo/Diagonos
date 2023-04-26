#include<stdio.h>
#include<stdlib.h>

typedef unsigned long long int ull;
ull map[75];

ull Fibonaci(ull n) {
	ull ret;
	if (n == 0) {
		ret = 0;
		map[0] = ret;

	}
	else if (n == 1 || n == 2) {
		map[1] = 1;
		map[2] = 1;
		ret = 1;
	}
	else {
		if (map[n] != 0)
			ret = map[n];
		else {
			ret = Fibonaci(n - 1) + Fibonaci(n - 2) + Fibonaci(n - 3);
			map[n] = ret;
		}
	}
	return ret;
}


 int main(void)
{
	int t;
	scanf_s("%d", &t);
	for (int i = 0; i < t; i++) {
		ull n = 0, ret = 0;
		scanf_s("%llu", &n);
		ret = Fibonaci(n);
		printf("case #%d:\n", i);
		printf("%llu\n", ret);

	}
	return 0;
}