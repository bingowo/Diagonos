#include<stdio.h>
#include<math.h>

struct point{
    double r,o;
};

int cmp(const void *a,const void *b){
    struct point *g1=(struct point*)a,*g2=(struct point*)b;
    double t1=(g1->r)-(g2->r),t2=(g1->o)-(g2->o);
    int t=0;
    if(t1>0)t=-1;
    if(t1<0)t=1;
    if(t2>0)t=1;
    if(t2<0)t=-1;
    return t;
}

int main(){
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        int n;
        double x,y;
        scanf("%d",&n);
        struct point p[n];
        for(int i=0;i<n;i++){
            scanf("%lf %lf",&x,&y);
            p[i].r=sqrt(x*x+y*y);
            if(x==0&&y>0)p[i].o=1.5708;
            else if(x==0&&y<0)p[i].o=4.7124;
            else if(y==0&&x>0)p[i].o=0;
            else if(y==0&&x<0)p[i].o=3.1416;
            else if(y/x==1.0){
                if(x>0)p[i].o=0.7854;
                else p[i].o=3.9270;
            }
            else if(y/x==-1.0){
                if(x>0)p[i].o=5.4978;
                else p[i].o=2.3562;
            }
            else if(y<0)p[i].o=2*3.1415926-atan2(y,x);
            else p[i].o=atan2(y,x);
        }
        qsort(p,n,sizeof(struct point),cmp);
        printf("case #%d:\n",a);
        for(int i=0;i<n;i++)printf("(%.4f,%.4f)\n",p[i].r,p[i].o);
        a++;
    }
    return 0;
}