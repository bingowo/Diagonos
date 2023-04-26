#include<stdio.h>
#include<stdlib.h>

struct point{
    int x,y;
};

int cmp(const void *a,const void *b){
    struct point *g1=(struct point*)a,*g2=(struct point*)b;
    int x1=g1->x,x2=g2->x,y1=g1->y,y2=g2->y;
    int d1=abs(x1)+abs(y1),d2=abs(x2)+abs(y2);
    if(d1!=d2)return d2-d1;
    if(x1!=x2)return x1-x2;
    return y1-y2;
}

int main(){
    int n,d;
    scanf("%d",&n);
    struct point p[n];
    for(int i=0;i<n;i++)scanf("%d %d",&p[i].x,&p[i].y);
    qsort(p,n,sizeof(struct point),cmp);
    d=abs(g[0].x-g[1].x)+abs(g[0].y-g[1].y);
    printf("%d\n",d);
}