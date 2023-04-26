#include <stdio.h>
#include <stdlib.h>

typedef long long int lli;

int CountOne(lli x)
{
	int cnt = 0;
	lli mask = 1;
	for(int i = 0 ; i < 64 ; i ++){
		if(mask & x){
			cnt ++;
		}
		x = x >> 1;
	}

	return cnt;
}

int cmp(const void *a, const void *b)
{
	lli na = *(lli *)a;
	lli nb = *(lli *)b;
	int oa = CountOne(na), ob = CountOne(nb);
	if(oa != ob){
		return ob - oa;
	}else{
		return na > nb ? 1 : -1;
	}
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t; i ++){
		int n;
		scanf("%d", &n);
		lli num[n];
		for(int j = 0 ; j < n ; j ++){
			scanf("%lld", &num[j]);
		}
		qsort(num, n, sizeof(lli), cmp);
		printf("case #%d:\n", i);
		for(int j = 0 ; j < n; j ++){
			printf("%lld%c", num[j], j == n - 1 ? '\n' : ' ');
		}
	}

	return 0;
}
