#include <stdio.h>
#include <stdlib.h>
long long a[1000010];
int cmp(const void *a, const void *b){
	const long long *pa = a, *pb = b;
	if((*pa) < (*pb))	return 1;
	else	return -1;
}
int main(){
	int n, m, i, j;
	long long maxn = 0, ans = 0;
	scanf("%d%d", &n, &m);
	for(i = 0; i < n; ++i){
		scanf("%lld", &a[i]);
	}
	qsort(a, n, sizeof(a[0]), cmp);
	for(i = 0; i < n; ++i){
		ans = 0;
		for(j = i + 1; j < i + m && i + m < n; ++j){
			ans += a[j] - a[i];
		}
		if(ans > maxn)	maxn = ans;
	}
	printf("%lld", maxn);
	return 0;
}