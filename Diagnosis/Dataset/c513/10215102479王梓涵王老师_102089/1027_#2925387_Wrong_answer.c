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

int main()
{
	int T;
	scanf("%d",&T);
	int i=0;
	for(i;i<T;i++)
	{
		int n;
		scanf("&d",&n);
		Point pset[n];
		int j;
		for(j=0;j<n;j++)
		{
			scanf("%lf %lf",&pset[j].x,&pset[j].y);
			pset[j].r=sqrt(pset[j].x*pset[j].x+pset[j].y*pset[j].y);
			pset[j].th=atan2(pset[j].y,pset[j].x);
			if (pset[j].th<0)
			{
				pset[j].th+=2*pi;
			}
		}

		qsort(pset, n, sizeof(Point),cmp);
		printf("case #%d:\n", i);
		for(j = 0 ; j < n; j ++){
			printf("(%.4f,%.4f)\n", pset[j].r, pset[j].th);
		}
	}
	return 0;
}