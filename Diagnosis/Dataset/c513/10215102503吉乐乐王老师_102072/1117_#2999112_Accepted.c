#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define lli long long int
lli myabs(lli n){
    return n<0?-n:n;
}
struct {
    lli x0;
    lli y0;
}p;
typedef struct{
    lli x;
    lli y;
    lli dis;
}point;
lli cmp(const void *a,const void *b){
    point pa=*(point*)a;
    point pb=*(point*)b;
    if(pa.dis==pb.dis){
        if(pa.x==pb.x)return pa.y>pb.y?1:-1;
        return pa.x>pb.x?1:-1;
    }
    return pa.dis>pb.dis?1:-1;
}
lli main(){
    scanf("%lld %lld",&p.x0,&p.y0);
    lli n;
    scanf("%lld",&n);
    point *a=(point*)malloc(n*sizeof(point));
    for(lli i=0;i<n;i++){
        scanf("%lld %lld",&a[i].x,&a[i].y);
        a[i].dis=fmax(myabs(a[i].x-p.x0),myabs(a[i].y-p.y0));
    }
    qsort(a,n,sizeof(a[0]),cmp);
    printf("%lld\n%lld %lld",a[0].dis,a[0].x,a[0].y);
    return 0;
}