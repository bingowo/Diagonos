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
    int retmax =0;
    for(int j=0;j<n;j++){
        ret[j] = 2 * a[j].r * a[j].r + a[j].s;
        for(int p=0,q=0;p<m-1;q++){
            if(q!=j){
                ret[j] = ret[j] + a[q].s;
                p++;
            }
        }
        if(retmax < ret[j]){
            retmax = ret[j];
        }
    }
    printf("%d",ret[0]);
    return 0;
}
