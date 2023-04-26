#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct cds{
    long long int x;
    long long int y;
    unsigned long long int len;
};

int cmp(const void*a,const void*b){
    struct cds m=*(struct cds*)a;
    struct cds n=*(struct cds*)b;
    if(m.len==n.len){
        if(m.x==n.x){
            return m.y>n.y;
        }
        else return m.x>n.x;
    }
    else return m.len>n.len;
}

int main(){
    long long int x0,y0;
    scanf("%lld%lld",&x0,y0);
    int n;
    struct cds p[n]; 
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&p[i].x,&p[i].y);
        if((abs(p[i].x)-abs(x0))>(abs(p[i].y)-abs(y0)))p[i].len=abs(p[i].x)-abs(x0);
        else p[i].len=abs(p[i].y)-abs(y0);
    }
    qsort(p,n,sizeof(p[0]),cmp);
    printf("%lld %lld\n",p[0].x,p[0].y);
}