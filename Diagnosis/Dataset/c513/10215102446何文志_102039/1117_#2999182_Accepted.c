#include <stdio.h>
#include <stdlib.h>
typedef struct Point{
    long long x;
    long long y;
    long long dis;
}pt;

long long max(long long n1, long long n2){
    return n1>n2 ? n1 : n2;
}

long long myAbs(long long n1, long long n2){
    return n1>n2 ? n1-n2 : n2-n1;
}

long long ChebyshevDistance(pt p1, pt p2){
    long long dx = myAbs(p1.x, p2.x);
    long long dy = myAbs(p1.y, p2.y);
    return max(dx, dy);

}

int cmp(const void *a, const void *b){
    pt A = *(pt*)a, B = *(pt*)b;
    if(A.dis!=B.dis){
        return A.dis>B.dis ? 1 : -1;
    }
    else if(A.x!=B.x){
        return A.x>B.x ? 1 : -1;
    }
    else{
        return A.y> B.y ? 1 : (A.y==B.y ? 0 : -1);
    }
}

int main()
{
    pt p0 = {0,0,0};
    scanf("%lld%lld",&p0.x,&p0.y);
    int n = 0;
    scanf("%d",&n);
    pt points[n];memset(points,0,n*sizeof(pt));
    for(int i = 0;i<n;i++){
        scanf("%lld%lld",&points[i].x,&points[i].y);
        points[i].dis = ChebyshevDistance(points[i],p0);
    }
    qsort(points,n,sizeof(points[0]),cmp);
//    for(int i = 0;i<n;i++){
//        printf("x = %lld, y = %lld, dis = %lld\n"
//               ,points[i].x,points[i].y,points[i].dis);
//    }


    printf("%lld\n",points[0].dis);
    printf("%lld %lld\n",points[0].x,points[0].y);
    return 0;
}
