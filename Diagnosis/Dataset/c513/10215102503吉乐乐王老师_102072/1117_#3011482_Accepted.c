#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//#define lli long long int
long long int myabs(long long int  n){
    return n<0?-n:n;
}
struct {
    long long int  x0;
    long long int  y0;
}p;
typedef struct{
    long long int  x;
    long long int  y;
    long long int  dis;
}point;
long long int  cmp(const void *a,const void *b){
    point pa=*(point*)a;
    point pb=*(point*)b;
    if(pa.dis==pb.dis){
        if(pa.x==pb.x)return pa.y>pb.y?1:-1;
        return pa.x>pb.x?1:-1;
    }
    return pa.dis>pb.dis?1:-1;
}
int  main(){
    scanf("%lld %lld",&p.x0,&p.y0);
    long long int  n;
    scanf("%lld",&n);
    point *a=(point*)malloc(n*sizeof(point));
    for(long long int  i=0;i<n;i++){
        scanf("%lld %lld",&a[i].x,&a[i].y);
        a[i].dis=fmax(myabs(a[i].x-p.x0),myabs(a[i].y-p.y0));
    }
    qsort(a,n,sizeof(a[0]),cmp);
    printf("%lld\n%lld %lld",a[0].dis,a[0].x,a[0].y);
    return 0;
    free(a);
}