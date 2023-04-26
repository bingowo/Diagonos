#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define PI 3.14159265358979323846
typedef struct {
	double x;
	double y;
	double sita;
	double len;
	
}POINT;
int cmp(const void*a,const void*b){
	double sa=((POINT*)a)->sita,sb=((POINT*)b)->sita;
	if(sa==sb) return ((POINT*)b)->len-((POINT*)a)->len;
	else return (sa-sb)>0?1:-1;
}
int main(){
	int T,N;
	double x,y;
	POINT p[1001];
	scanf("%d\n",&T);
	for(int i=0;i<T;i++){
		scanf("%d\n",&N);
		for(int j=0;j<N;j++){
			scanf("%lf %lf\n",&p[j].x,&p[j].y);
			double x1=p[j].x,y1=p[j].y;
			p[j].len=sqrt(x1*x1+y1*y1);
			p[j].sita=atan2(p[j].y,p[j].x);
			if((p[j].sita)<0) p[j].sita+=2*PI;
			}
		qsort(p,N,sizeof(POINT),cmp);
		printf("case #%d:\n",i);
		for(int k=0;k<N;k++)
		{
			printf("(%.4lf,%.4lf)\n",p[k].len,p[k].sita);
		}
	}
	
	return 0;
}