#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.1415926535

typedef struct {
	double x, y, p, p0;
}point;

int cmp(const void *_a, const void *_b){
	point a = *(point *)_a;
	point b = *(point *)_b;
	
	if (a.p0 > b.p0)
		return 1;
	if (a.p0 < b.p0)
		return -1;
	return b.p - a.p;
}

int main()
{
	int ncase, T;
	scanf("%d",&T);
	for (ncase = 0; ncase < T; ncase++) {
		int n;
		scanf("%d",&n);
		point a[n];
		
		for (int i = 0; i < n; i++){
			scanf("%lf%lf",&a[i].x, &a[i].y);
			a[i].p = sqrt(a[i].x * a[i].x + a[i].y * a[i].y);
			a[i].p0 = atan2(a[i].y, a[i].x);
			if (a[i].p0 < 0)
				a[i].p0 += 2*PI;
		}
		
		qsort(a, n, sizeof(a[0]), cmp);

		//输出
		printf("case #%d:\n",ncase);
		for (int i = 0; i < n; i++)
			printf("(%.4f,%.4f)\n", a[i].p, a[i].p0);
	}
	return 0;
}