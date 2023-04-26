#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<malloc.h>
#define PI 3.1415926
struct coordinate{
    double x,y;
    double a,p;
}*dot;

int cmp(const void *a,const void *b){
    struct coordinate *dot1=(struct coordinate *)a;
    struct coordinate *dot2=(struct coordinate *)b;
    if((dot1->a)!=(dot2->a))
        return (dot1->a)-(dot2->a);
    else return (dot2->p)-(dot1->p);
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int N;
        scanf("%d",&N);
        dot=(struct coordinate*)malloc(sizeof(struct coordinate)*N);
        for(int i=0;i<N;i++){
            scanf("%lf%lf",&dot[i].x,&dot[i].y);
            dot[i].p=sqrt(dot[i].x*dot[i].x+dot[i].y*dot[i].y);
            dot[i].a=atan(dot[i].y/dot[i].x);
            if(dot[i].x>0&&dot[i].y>0){
                while(dot[i].a<0)
                    dot[i].a+=PI/2;
                while(dot[i].a>PI/2)
                    dot[i].a-=PI/2;
            }
            if(dot[i].x<0&&dot[i].y>0){
                while(dot[i].a<PI/2)
                    dot[i].a+=PI/2;
                while(dot[i].a>PI)
                    dot[i].a-=PI/2;
            }
            if(dot[i].x<0&&dot[i].y<0){
                while(dot[i].a<PI)
                    dot[i].a+=PI/2;
                while(dot[i].a>3*PI/2)
                    dot[i].a-=PI/2;
            }
            if(dot[i].x>0&&dot[i].y<0){
                while(dot[i].a<3*PI/2)
                    dot[i].a+=PI/2;
                while(dot[i].a>2*PI)
                    dot[i].a-=PI/2;
            }
        }
        qsort(dot,N,sizeof(dot[0]),cmp);
        printf("case #%d:\n",t);
        for(int i=0;i<N;i++){
            printf("(%.4f,%.4f)\n",dot[i].p,dot[i].a);
        }
    }
    return 0;
}

