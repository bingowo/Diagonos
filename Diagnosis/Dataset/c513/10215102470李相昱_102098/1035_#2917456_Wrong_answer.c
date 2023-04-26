#include <stdio.h>
#include <stdlib.h>
typedef struct {
    double h;
    double r;
    double s;
}vec;
int cmp(const void*p1,const void *p2){
    vec *a =(vec *)p1;
    vec *b=(vec *)p2;
    return a->s >b->s ?-1:1;
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    vec a[n];
    double rmax = 0;
    for(int i=0;i<n;i++){
        scanf("%lf",&a[i].r);
        scanf("%lf",&a[i].h);
        a[i].s = 2 * a[i].r *  a[i].h ; 
        if(a[i].r > rmax){
            rmax = a[i].r;
        }
    }
    qsort(a,n, sizeof(vec),cmp);
    double ret = 0;
    for(int j=0;j<m;j++){
        ret = ret + a[j].s;
    }
    ret = ret + 2 * rmax * rmax;
    printf("%lf",ret);
    return 0;
}

