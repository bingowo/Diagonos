#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pai 3.1415926
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct{
	double p;double u;
}point;
int cmp(const void*a,const void*b){
point p1=*(point*)a;
	point p2=*(point*)b;
	if(p1.u>p2.u) return 1;
	if(p1.u<p2.u) return -1;
 if(p1.u==p2.u) return p2.p-p1.p;
}
int main(int argc, char *argv[]) {
	int i,j,k,T,N;
	double x,y;
	scanf("%d\n",&T);
	point *s;
	for(k=0;k<T;k++){
		printf("case #%d:\n",k);
		scanf("%d\n",&N);
		s=(point*)malloc(N*sizeof(point));
		for(j=0;j<N;j++){
			scanf("%lf%lf",&x,&y);
			s[j].p=sqrt(pow(x,2)+pow(y,2));
			if(y>=0){
				if(x>0) s[j].u=atan(y/x);
				else if(x<0) s[j].u=atan(y/x)+pai;
				else if(x==0) s[j].u=pai/2;
			}
			else{
				if(x<0) s[j].u=atan(y/x)+pai;
				if(x>0) s[j].u=atan(y/x)+2*pai;
				if(x==0) s[j].u=3*pai/2;
			}
		}qsort(s,N,sizeof(s[0]),cmp);
		for(j=0;j<N;j++){
			printf("(%.4lf,%.4lf)\n",s[j].p,s[j].u);
		}
		
	}free(s);
	return 0;
}