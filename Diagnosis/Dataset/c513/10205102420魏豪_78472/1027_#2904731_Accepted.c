#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct{
	double x;
	double y;
	double len;
	double ang;
}Point;
int cmp(const void*a,const void*b);
int main(){
	int T,k;
	scanf("%d",&T);
	for(k=0;k<T;k++){
		int n,i;
        double pi=3.1415926535;
		scanf("%d",&n);
	    Point p[1000];
		for(i=0;i<n;i++){
			scanf("%lf %lf",&p[i].x,&p[i].y);
			double qrt=(p[i].x)*(p[i].x)+(p[i].y)*(p[i].y);
			p[i].len=sqrt(qrt);
			if(p[i].x>0){
				if(p[i].y==0){
					p[i].ang=0;
				}
				else if(p[i].y>0){
					p[i].ang=atan(p[i].y/p[i].x);
				}
				else if(p[i].y<0){
					p[i].ang=atan(p[i].y/p[i].x)+pi*2;
				}
			}
			else if(p[i].x==0){
				if(p[i].y>0){
					p[i].ang=atan(p[i].y/p[i].x);
				}
				else if(p[i].y<0){
					p[i].ang=atan(p[i].y/p[i].x)+pi*2;
				}
				else if(p[i].y==0){
					p[i].ang=0;
				}
			}
			else if(p[i].x<0){
				if(p[i].y==0){
					p[i].ang=pi;
				}
				else if(p[i].y>0){
					p[i].ang=atan(p[i].y/p[i].x)+pi;
				}
				else if(p[i].y<0){
					p[i].ang=atan(p[i].y/p[i].x)+pi;
				}
			}
		}
		qsort(p,n,sizeof(p[0]),cmp);
		printf("case #%d:\n",k);
		for(i=0;i<n;i++){
			printf("(%.4f,%.4f)\n",p[i].len,p[i].ang);
	    }
	}
	return 0;
} 

int cmp(const void*a,const void*b){
	Point s1,s2;
	s1=*(Point*)a;
	s2=*(Point*)b;
    if(s1.ang==s2.ang){
        if(s2.len>s1.len){
            return 1;
        }
        else{
            return -1;
        }
    }
   if(s1.ang>s2.ang){
       return 1;
   }
   return -1;
}