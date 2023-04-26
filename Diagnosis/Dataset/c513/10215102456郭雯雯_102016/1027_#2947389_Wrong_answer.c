#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct point{
    double r,o;
};

double cmp(const void *a,const void *b){
    struct point *g1=(struct point*)a,*g2=(struct point*)b;
    double t1=(g1->o)-(g2->o),t2=(g2->r)-(g1->r);
    
    return t1;
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
            if(x==0&&y<0)p[i].o=4.7124;
            if(y==0&&x>0)p[i].o=0;
            if(y==0&&x<0)p[i].o=3.1416;
            p[i].o=tan(y/x);
        }
        qsort(p,n,sizeof(struct point),cmp);
        printf("case #%d:\n",a);
        for(int i=0;i<n;i++)printf("(%.4f,%.4f)\n",p[i].r,p[i].o);
        a++;
    }
    
}