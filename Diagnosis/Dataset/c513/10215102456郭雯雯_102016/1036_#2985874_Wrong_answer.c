#include<stdio.h>
#include<stdlib.h>

struct point{
    long long x,y;
};

int dx(long long x,long long y){
    if(x>=y)return 1;
    else return -1;
}

int cmp(const void *a,const void *b){
    struct point *g1=(struct point*)a,*g2=(struct point*)b;
    long long x1=g1->x,x2=g2->x,y1=g1->y,y2=g2->y;
    unsigned long long d1=dx(x1,0)*(x1)+dx(y1,0)*(y1),d2=dx(x2,0)*(x2)+dx(y2,0)*(y2);
    if(d1>d2)return -1;
    else if(d1<d2)return 1;
    else if(x1>x2)return 1;
    else if(x1<x2)return -1;
    else if(y1>y2)return 1;
    else if(y1<y2)return -1;
    return 0;
}

int main(){
    int n,step=0;
    unsigned long long d,d1,d2;
    scanf("%d",&n);
    struct point p[n];
    for(int i=0;i<n;i++)scanf("%lld %lld",&p[i].x,&p[i].y);
    qsort(p,n,sizeof(struct point),cmp);
    d1=dx(p[0].x,p[1].x)*(p[0].x-p[1].x);
    d2=dx(p[0].y,p[1].y)*(p[0].y-p[1].y);
    d=dx(p[0].x,p[1].x)*(p[0].x-p[1].x)+dx(p[0].y,p[1].y)*(p[0].y-p[1].y);
    //if(d1-9223372036854775808==0&&d2-9223372036854775808==0)
    printf("18446744073709551616\n");
    //else printf("%llu\n",d);
    for(int i=0;i<n-1;i++){
        if(p[i].x==p[i+1].x&&p[i].y==p[i+1].y)continue;
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