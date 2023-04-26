#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{
	double r;
	double o;
}Point;
int cmp(const void *p1,const void *p2){
	Point *a = (Point *)p1;
	Point *b = (Point *)p2;
	if(a->o>b->o)
		return 1;
	if(a->o<b->o)
		return -1;
	if(a->r>b->r)
		return -1;
	if(a->r<b->r)
		return 1;
}
double fbs(double a){
	if(a<0)
		return -a;
	return a;
}
int main()
{
	const double pi=3.1415926535;
	int T,n;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%d",&n);
		double x,y;
		Point point[n];
		for(int j=0;j<n;j++){
			scanf("%lf %lf",&x,&y);
			point[j].r=sqrt(x*x+y*y);
			if(x==0){
				if(y>0)
					point[j].o=pi/2;
				if(y<0)
					point[j].o=pi/2+pi;	
			}else if(x>0){
				if(y>=0)
					point[j].o=atan(y/x);
				if(y<0)
					point[j].o=atan(y/x)+2*pi;
			}else{
					point[j].o=atan(y/x)+pi;
			}		
		}
		qsort(point,n,sizeof(Point),cmp);
		printf("case #%d:\n",i);
		for(int j=0;j<n;j++){
			printf("(%.4f,%.4f)\n",point[j].r,point[j].o);
		}
	}
	return 0;
}