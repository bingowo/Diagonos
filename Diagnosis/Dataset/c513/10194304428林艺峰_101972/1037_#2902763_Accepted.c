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
	long long minn = 0, ans = 0;
	scanf("%d%d", &n, &m);
	for(i = 0; i < n; ++i){
		scanf("%lld", &a[i]);
	}
	qsort(a, n, sizeof(a[0]), cmp);
	for(i = 1; i < m; ++i)	ans += a[0] - a[i];
	minn = ans;
	for(i = 1; i <= n - m; ++i){
		ans = ans - (a[i-1] - a[i]) * (m - 1) + a[i] - a[i+m-1];
		if(ans < minn)	minn = ans;
	}
	printf("%lld", minn);
	return 0;
}