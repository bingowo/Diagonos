#include<stdio.h>
#include<stdlib.h>

struct point{
    long long x,y;
};

int cmp(const void *a,const void *b){
    struct point *g1=(struct point*)a,*g2=(struct point*)b;
    int x1=g1->x,x2=g2->x,y1=g1->y,y2=g2->y;
    int d1=abs(x1)+abs(y1),d2=abs(x2)+abs(y2);
    if(d1!=d2)return d2-d1;
    if(x1!=x2)return x1-x2;
    return y1-y2;
}

int dx(long long x,long long y){
    if(x>=y)return 1;
    else return -1;
}

int main(){
    int n,step=0;
    unsigned long long d;
    scanf("%d",&n);
    struct point p[n];
    for(int i=0;i<n;i++)scanf("%lld %lld",&p[i].x,&p[i].y);
    qsort(p,n,sizeof(struct point),cmp);
    d=abs(p[0].x-p[1].x)+abs(p[0].y-p[1].y);
    printf("%ulld\n",d);
    for(int i=0;i<n-1;i++){
        d=dx(p[i].x,p[i+1].x)*(p[i].x-p[i+1].x)+dx(p[i].y,p[i+1].y)*(p[i].y-p[i+1].y);
        if(d%2==0)break;
        else{
            int j=0;
            while(d!=0){d/=2;j++;}
            step+=j;
        }
    }
    printf("%d\n",step);
    return 0;
}