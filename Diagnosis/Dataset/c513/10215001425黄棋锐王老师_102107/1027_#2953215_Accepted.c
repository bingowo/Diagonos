#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
  #define pi 3.1415926
typedef struct{
	double x;
	double y;
}coo;
void change(coo*p,int N){
	int j=0;
	for(j=0;j<N;j++){
		double xx=p[j].x;
		double yy=p[j].y;
		p[j].x=sqrt(pow(xx,2)+pow(yy,2));
		if(xx!=0)
		{if(xx>0)
				{  
			      if(yy>0) p[j].y=atan(yy/xx);
			      else if(yy<0) p[j].y=2*pi+atan(yy/xx);
			      else if(yy==0) p[j].y=0;
		          }
			else{
				if(yy>0) p[j].y=pi+atan(yy/xx);
				else if(yy<0) p[j].y=pi+atan(yy/xx);
				else if(yy==0) p[j].y=pi;
			}
			}
		else {
			if(yy==0) p[j].y=0;
			if(yy>0) p[j].y=pi/2;
			if(yy<0) p[j].y=(pi*3)/2;
		}
	}
}
int cmp(const void*a,const void*b){
	coo*aa=(coo*)a;
	coo*bb=(coo*)b;
	if(aa->y!=bb->y){
		if(aa->y>bb->y) return 1;
		else return -1;
	}
	else {
		if(bb->x>aa->x) return 1;
		else return -1;
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
	      qsort(p,N,sizeof(p[0]),cmp);
		  printf("case #%d:\n",k);
		   for(i=0;i<N;i++)
				printf("(%.4lf,%.4lf)\n",p[i].x,p[i].y);
				free(p);
	}
		return 0;
}