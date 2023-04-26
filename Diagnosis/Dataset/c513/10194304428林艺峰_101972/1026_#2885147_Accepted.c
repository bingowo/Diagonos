#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int x[100010];
int cmp(const void *a, const void *b){
	const int *pa = a, *pb = b;
	return *pa - *pb;
}
int main(){
	int n, i;
	long long ans = 0;
	scanf("%d", &n);
	for(i = 0; i < n; ++i){
		scanf("%d", &x[i]);
	}
	qsort(x, n, sizeof(x[0]), cmp);
	for(i = 1; i < n; i += 2){
		ans += x[i] - x[i-1];
	}
	printf("%lld", ans);
}