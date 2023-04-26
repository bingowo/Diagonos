#include<stdio.h>
#include<stdlib.h>

typedef long long int lli;

lli CountWays(lli n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else if (n == 2) return 2;
	else if (n == 3) return 4;
	else if (n == 4) return 8;
	else {
		return CountWays(n - 1) + CountWays(n - 2) + CountWays(n - 3) + CountWays(n - 4);
	}

}
int main() {
	int t;
	lli ret,n;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%lld", &n);
		ret = CountWays(n);
		printf("case #%d:\n", i);
		printf("%lld", ret);
	
	}	
	return 0;
}