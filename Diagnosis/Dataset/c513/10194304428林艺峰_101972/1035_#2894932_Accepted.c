#include <stdio.h>
#include <stdlib.h>
struct circle{
	long long r, h, s;
}a[1010];
int cmp(const void *a, const void *b){
	const struct circle *pa = a, *pb = b;
	if((*pa).s != (*pb).s){
		if((*pa).s < (*pb).s)	return 1;
		else	return -1;
	}
	else{
		if((*pa).r < (*pb).r)	return 1;
		else	return -1;
	}
}
int main(){
	int n, m, i, j, count;
	scanf("%d%d", &n, &m);
	for(i = 0; i < n; ++i){
		scanf("%lld%lld", &a[i].r, &a[i].h);
		a[i].s = 2 * a[i].r * a[i].h;
	}
	qsort(a, n, sizeof(a[0]), cmp);
	long long maxn = 0;
	for(i = 0; i < n; ++i){
		long long ans = a[i].s + a[i].r * a[i].r;
		count = 1;
		for(j = 0; j < n && count < m; ++j){
			if(a[j].r <= a[i].r && i != j){
				ans += a[j].s;
				count += 1;
			}
		}
		if(count == m){
			if(ans > maxn)	maxn = ans;
		}
	}
	printf("%lld", maxn);
	return 0;
}