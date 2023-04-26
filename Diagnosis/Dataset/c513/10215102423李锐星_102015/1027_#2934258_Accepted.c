#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.1415926
typedef struct{
	double r;
	double angle;
}POINT;

int cmp(const void* a,const void* b)
{
	POINT A,B;
	A=*(POINT*)a;
	B=*(POINT*)b;
	if (A.angle<B.angle){
		return -1;
	}
	else if (A.angle>B.angle){
		return 1;
	}
	else {
		if (A.r>B.r){
			return -1;
		}
		else if (A.r<B.r){
			return 1;
		}
	}
}


int main()
{
	int T;
	scanf("%d",&T);
	int i,j;
	int n;
	POINT *A;
	for (i=0;i<T;i++){
		scanf("%d",&n);
		A=(POINT*)malloc(n*sizeof(POINT));
		printf("case #%d:\n",i);
		for (j=0;j<n;j++){
			double x,y;
			scanf("%lf %lf",&x,&y);
			A[j].r=sqrt(x*x+y*y);
			double a;
			a=atan2(y,x);
			if (a<0){
				a+=2*pi;
			}
			A[j].angle=a;
		}
		qsort(A,n,sizeof(POINT),cmp);
		for (j=0;j<n;j++){
			printf("(%.4f,%.4f)\n",A[j].r,A[j].angle);
		}
		free(A);
	}
	return 0;
}