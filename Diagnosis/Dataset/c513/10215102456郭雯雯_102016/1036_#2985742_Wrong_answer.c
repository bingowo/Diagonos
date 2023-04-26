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
    int n,d,step=0;
    scanf("%d",&n);
    struct point p[n];
    for(int i=0;i<n;i++)scanf("%d %d",&p[i].x,&p[i].y);
    qsort(p,n,sizeof(struct point),cmp);
    d=abs(p[0].x-p[1].x)+abs(p[0].y-p[1].y);
    printf("%d\n",d);
    for(int i=0;i<n-1;i++){
        d=abs(p[i].x-p[i+1].x)+abs(p[i].y-p[i+1].y);
        if(d%2==0)break;
        else{
            int j=0;
            while(d!=0){d/=2;j++;}
            step+=j;
        }
    }
    printf("%d\n",step);
}