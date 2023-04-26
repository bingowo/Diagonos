#include<stdio.h>
#include<stdlib.h>
struct circle{
	long long r, h, s1, s2;
}a[1010];
int cmp(const void *a, const void *b){
	const struct circle *pa = a, *pb = b;
	if((*pa).s1 != (*pb).s1){
		if((*pa).s1 < (*pb).s1)	return 1;
		else return -1;
	}
	else{
		if((*pa).s2 < (*pb).s2)	return 1;
		else return -1;
	}
}
int main(){
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for(i = 0; i < n; ++i){
		scanf("%lld%lld", &a[i].r, &a[i].h);
		a[i].s1 = a[i].r * a[i].r;
		a[i].s2 = 2 * a[i].r * a[i].h;
	}
	qsort(a, n, sizeof(a[0]), cmp);
	long long maxn = 0, ans = 0;
	for(i = 0; i < n; ++i){
		ans = a[i].s1;
		for(j = i; j < m + i; ++j){
			ans += a[j].s2;
		}
		if(ans > maxn)	maxn = ans;
	}
	printf("%lld", maxn);
	return 0;
}