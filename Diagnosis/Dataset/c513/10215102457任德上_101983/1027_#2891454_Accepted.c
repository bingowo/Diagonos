#include<stdio.h>
#include<malloc.h>
#include<math.h>
struct dot{
    double x,y;
    double angle;
    double polar;
};
int cmp(const void *a,const void *b){
    struct dot *m1,*m2;
    m1=(struct dot*)a;
    m2=(struct dot*)b;
    if(m1->angle==m2->angle){
        if(m2->polar>m1->polar)return 1;
        else return -1;
    }
    else if(m1->angle>m2->angle)return 1;
    else return -1;

}
int main(){
    int T,cas=0;
    double pi=acos(-1.0);
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N;
        scanf("%d",&N);
        struct dot *a;
        a=(struct dot*)malloc(N*sizeof(struct dot));
        for(int k=0;k<N;k++){
            scanf("%lf%lf",&(a+k)->x,&(a+k)->y);
            int x2,y2,x1,y1;
            x1=(a+k)->x;
            y1=(a+k)->y;
            x2=pow((a+k)->x,2);
            y2=pow((a+k)->y,2);
            (a+k)->polar=sqrt(x2+y2);
            if((a+k)->x!=0)(a+k)->angle=atan((a+k)->y/(a+k)->x);
            else if((a+k)->y>=0)(a+k)->angle=pi/2;
            else (a+k)->angle=3.0*pi/2;
            if (x1*y1<0&&y1>0)(a+k)->angle+=pi;
            else if(x1*y1<0&&y1<0)(a+k)->angle+=2*pi;
            else if(x1<0&&y1<0)(a+k)->angle+=pi;
            else if(y1==0&&x1<0)(a+k)->angle+=pi;
        }
        qsort(a,N,sizeof(struct dot),cmp);
        printf("case #%d:\n",cas++);
        for(int k=0;k<N;k++)printf("(%.4lf,%.4lf)\n",(a+k)->polar,(a+k)->angle);
        free(a);
    }

    return 0;
}
