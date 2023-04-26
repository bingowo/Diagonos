#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int h;
    int r;
    int s;
}vec;
int cmp(const void*p1,const void *p2){
    vec *a =(vec *)p1;
    vec *b=(vec *)p2;
    return a->s >b->s ?-1:1;
}
int cmp1(const void *p1,const void *p2){
    int * a=(int *)p1;
    int * b=(int *)p2;
    return *b-*a;
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    vec a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].r);
        scanf("%d",&a[i].h);
        a[i].s = 2 * a[i].r *  a[i].h ;
    }
    qsort(a,n, sizeof(vec),cmp);
    int ret[n];
    for(int j=0;j<n;j++){
        ret[j] = 2 * a[j].r * a[j].r + a[j].s;
        for(int p=0,q=0;p<m-1;q++){
            if(q!=j){
                ret[j] = ret[j] + a[q].s;
                p++;
            }
        }
    }
    qsort(ret,n,sizeof(int),cmp1);
    printf("%d",ret[0]);
    return 0;
}
