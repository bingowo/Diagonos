#include<stdio.h>
#include<stdlib.h>
struct circle{
	int r, h;
	long long s1, s2;
}a[1010];
int cmp(const void *a, const void *b){
	const struct circle *pa = a, *pb = b;
	if((*pa).s2 != (*pb).s2){
		if((*pa).s2 < (*pb).s2)	return 1;
		else return -1;
	}
	else{
		if((*pa).s1 < (*pb).s1)	return 1;
		else return -1;
	}
}
int main(){
	int n, m, i;
	scanf("%d%d", &n, &m);
	for(i = 0; i < n; ++i){
		scanf("%d%d", &a[i].r, &a[i].h);
		a[i].s1 = a[i].r * a[i].r;
		a[i].s2 = 2 * a[i].r * a[i].h;
	}
	qsort(a, n, sizeof(a[0]), cmp);
	long long maxn = 0;
	for(i = 1; i < m; ++i){
		ans += a[i].s2;
	}
	printf("%lld", ans);
	return 0;
}