#include<stdio.h>
#include<math.h>
#define pi 3.141592653
#define ep 1e-8
typedef struct{
	double x;
	double y;
	double p;
	double o;
}func;
int cmp(const void *a, const void *b)
{
	func x,y;
	x=*(func*)a;
	y=*(func*)b;
	if(fabs(x.o - y.o) > ep){
		return (x.o - y.o) > ep  ? 1 : -1;
	}else{
		return (x.p - y.p) < ep  ? 1 : -1;
	}
}
int main(){
	int chance;
	scanf("%d",&chance);
	int i;
	for(i=0;i<chance;i++){
		int n;
		scanf("%d",&n);
		int j;
		func a[1001];
		for(j=0;j<n;j++){
			scanf("%lf %lf",&a[j].x,&a[j].y);
			a[j].p=sqrt(a[j].x*a[j].x+a[j].y*a[j].y);
			a[j].o=atan2(a[j].y,a[j].x);
			if(a[j].o<0) a[j].o+=2*pi;
		}
		qsort(a,n,sizeof(func),cmp);
		printf("case #%d:\n",i);
		for(j=0;j<n;j++){
			printf("(%.4lf,%.4lf)\n",a[j].p,a[j].o);
		}
	}
} 