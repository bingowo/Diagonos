#include <stdio.h>
#include <stdlib.h>
typedef struct {
    long long int x;
    long long int y;
    unsigned long long int d0;
    unsigned long long int d;
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
    long long int pace =0;
    for(int j = 0;j<n-1;j++){
        points[j].d = llabs(points[j].x - points[j+1].x) +
                llabs(points[j].y - points[j+1].y);
        if(j==0){
            printf("%llu\n",points[0].d);
        }
        if((points[j].d %2)==0){
            break;
        }
        unsigned long long c = 1;
        for(int p=1;p<=64;p++){
            if(points[j].d <= ( c<<p)){
                pace +=p;
                break;
            }
            if(points[j].d>(c<<63)){
                pace +=64;
                break;
            }
        }
    }
    printf("%lld",pace);
    return 0;
}
