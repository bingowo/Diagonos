#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.1415926
struct lol{
	double length;
	double angle;
}a[1010];
int cmp(const void *a, const void *b){
	const struct lol *pa = a, *pb = b;
	if((*pa).angle != (*pb).angle){
		if((*pa).angle < (*pb).angle)	return -1;
		else return 1;
	}
	else{
		if((*pa).length > (*pb).length)	return -1;
		else return 1;
	}
}
int main(){
	int t, n, i, j;
	double x, y;
	scanf("%d",&t);
	for(i = 0; i < t; ++i){
		scanf("%d",&n);
		for(j = 0; j < n; ++j){
			scanf("%lf%lf", &x, &y);
			a[j].length = sqrt(x * x + y * y);
			a[j].angle = atan2(y, x);
			if(a[j].angle < 0)	a[j].angle += 2 * acos(-1);
		}
		qsort(a, n, sizeof(a[0]), cmp);
		printf("case #%d:\n",i);
		for(j = 0; j < n; ++j){
			printf("(%.4f,%.4f)\n",a[j].length,a[j].angle);
		}
	}
	return 0;
}