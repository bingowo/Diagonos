#include <stdio.h>
#include <stdlib.h>
typedef struct {
    long long int x;
    long long int y;
    long long int d0;
    long long int d;
}point;
int cmp(const void *p1,const void *p2){
    point *a= (point *)p1;
    point *b = (point *)p2;
    if(a->d != b->d){
        return a->d > b->d ? -1:1;
    }else if(a->x != b->x){
        return a->x >b->x ?1:-1;
    }else return a->y >b->y ?1:-1;
}

int main() {
    int n;
    scanf("%d",&n);
    point points[n];
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&points[i].x,&points[i].y);
        points[i].d0 = llabs(points[i].x) + llabs(points[i].y);
    }
    qsort(points,n,sizeof(point),cmp);
    long long int pace =1;
    for(int j = 0;j<n-1;j++){
        points[j].d = abs(points[j].x - points[j+1].x) +
                abs(points[j].y - points[j+1].y);
        while (points[j].d>1){
            pace ++;
            points[j].d = points[j].d /2;
        }
    }
    printf("%lld\n",points[0].d);
    printf("%lld\n",pace);
    return 0;
}
