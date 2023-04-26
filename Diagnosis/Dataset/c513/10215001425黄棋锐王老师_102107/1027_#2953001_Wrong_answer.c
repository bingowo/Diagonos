#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct{
	double x;
	double y;
}coo;
void change(coo*p,int N){
	int j=0;
	for(j=0;j<N;j++){
		double xx=p[j].x;
		double yy=p[j].y;
		p[j].x=sqrt(xx*xx+yy*yy);
		p[j].y=atan(yy/xx);
	}
}
 int main()
 {  int k,T,N;
    scanf("%d",&T);
	for(k=0;k<T;k++)
	{	scanf("%d",&N);
	 	coo* p;
		p=(coo*)malloc(N*sizeof(coo));
		int i;
		for(i=0;i<N;i++)
		{
			scanf("%lf %lf",&p[i].x,&p[i].y);
				
		}	    
	      change(p,N);
		  printf("case #%d:\n",k);
		   for(i=0;i<N;i++)
				printf("(%0.4lf,%0.4lf)\n",p[i].x,p[i].y);
	}
		return 0;
}