/*
Created by Shizumu on 2022/2/28.   
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const double ep = 1e-8;
const double pi = 3.1415926;

typedef struct{
	double x;
	double y;
	double r;
	double th;
}Point;

int cmp(const void *a, const void *b)
{
	Point *pa = (Point *)a;
	Point *pb = (Point *)b;
	int temp;
	if(fabs(pa->th - pb->th) > ep){
		return pa->th - pb->th > ep  ? 1 : -1;
	}else{
		return pa->r - pb->r < ep  ? 1 : -1;
	}
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t; i ++){
		int n;
		scanf("%d", &n);
		Point in[n];
		for(int j = 0 ; j < n ; j ++){
			scanf("%lf %lf", &in[j].x, &in[j].y);
			in[j].r = sqrt(in[j].x * in[j].x + in[j].y * in[j].y);
			in[j].th = atan2(in[j].y, in[j].x);
			if(in[j].th < 0){
				in[j].th += 2 * pi;
			}
		}
//		for(int j = 0 ; j < n ; j ++){
//			scanf("%lf %lf", &in[j].r, &in[j].th);
//		}
		qsort(in, n, sizeof(Point),cmp);
		printf("case #%d:\n", i);
		for(int j = 0 ; j < n; j ++){
			printf("(%.4f,%.4f)\n", in[j].r, in[j].th);
		}
	}
	return 0;
}