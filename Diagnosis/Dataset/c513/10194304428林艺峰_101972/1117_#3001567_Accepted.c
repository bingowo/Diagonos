#include <stdio.h>
#include <stdlib.h>
struct point{long long x, y, l;}p[1000010];
long long max(long long x, long long y){
	return (x>y)? x: y;
}
int cmp(const void *a, const void *b){
	const struct point *pa = a, *pb = b;
	if((*pa).l != (*pb).l){
		if((*pa).l > (*pb).l)	return 1;
		else	return -1;
	}
	if((*pa).x != (*pb).x){
		if((*pa).x > (*pb).x)	return 1;
		else	return -1;
	}
	if((*pa).y != (*pb).y){
		if((*pa).y > (*pb).y)	return 1;
		else	return -1;
	}
}
int main() {
	int n, i;
	long long x0, y0;
	scanf("%lld%lld", &x0, &y0); 
	scanf("%d", &n);
	for(i = 0; i < n; ++i){
		scanf("%lld%lld", &p[i].x, &p[i].y);
		p[i].l = max(llabs(p[i].x-x0), llabs(p[i].y-y0));
	}
	qsort(p, n, sizeof(p[0]), cmp);
	printf("%lld\n%lld %lld", p[0].l, p[0].x, p[0].y);
	return 0;
}