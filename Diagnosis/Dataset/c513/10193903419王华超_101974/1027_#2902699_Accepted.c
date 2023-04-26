#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#define N 1005
#define PI 3.1415926;
typedef struct{
	double x,y,p,angle;
}point;
int cmp(const void *p1,const void *p2){
	point a=*((point*)p1),b=*((point*)p2);
	if(a.angle!=b.angle){
		if(a.angle>b.angle) return 1;
		else{
			return -1;
		}
	}
	else{
		if (a.p>b.p){
			return -1;
		}
		else{
			return 1;
		}
	}
}
int main(int argc, char *argv[]) {
	int t,cas;
	scanf("%d",&t);
	for(cas=0;cas<t;cas++){
		int n,i;
		scanf("%d",&n);
		point l[N];
		for(i=0;i<n;i++){
			scanf("%lf %lf",&l[i].x,&l[i].y);
			l[i].p=sqrt(l[i].x*l[i].x+l[i].y*l[i].y);
			l[i].angle=atan2(l[i].y,l[i].x);
			if(l[i].angle<0){
				l[i].angle=l[i].angle+2*PI;
			}
		}
		qsort(l,n,sizeof(l[0]),cmp);
		printf("case #%d:\n",cas);
		for(i=0;i<n;i++){
			printf("(%.4f,%.4f)\n",l[i].p,l[i].angle);
		}
	}
	return 0;
}