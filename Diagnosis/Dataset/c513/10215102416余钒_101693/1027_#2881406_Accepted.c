#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int n,T; 
struct node{
	double v1,v2;
}A[100005];

int cmp(const void* a,const void* b){
	struct node x=*(struct node *)a,y=*(struct node *)b;
	if(fabs(x.v2-y.v2)>1e-10){
		if(x.v2>y.v2) return 1;
		else return -1;
	} 
	else {
		if(x.v1>y.v1) return -1;
		else return 1;
	}
}
int main() {
	scanf("%d",&T);
	for(int c=0;c<T;c++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			double v1,v2;
			scanf("%lf%lf",&v1,&v2);
			A[i].v1=sqrt(v1*v1+v2*v2);
			if(fabs(v1)<1e-8) A[i].v2=v2>0?asin(1):3*asin(1);
			else if(fabs(v2)<1e-8) A[i].v2=v1>0?0:acos(-1);
			else{
				A[i].v2=atan(v2/v1);
				if(v1<0&&v2<0) A[i].v2+=acos(-1);
				else if(v1>0&&v2<0) A[i].v2+=2*acos(-1);
				else if(v1<0&&v2>0) A[i].v2+=acos(-1);
			} 
		}	
		qsort(A+1,n,sizeof(struct node),cmp);
		printf("case #%d:\n",c);
		for(int i=1;i<=n;i++)
			printf("(%.4lf,%.4lf)\n",A[i].v1,A[i].v2);
	}
	return 0;
}