#include <stdio.h>
#include <stdlib.h>

typedef struct point{
    long long x;
    long long y;
}pt;

long long myabs(long long a,long long b){

    return (a>b? a-b:b-a);
}

long long manhatanDistance(pt p1, pt p2){
    return myabs(p1.x,p2.x) + myabs(p1.y,p2.y);
}

int cmp(const void *a, const void *b){
    pt A = *(pt*)a, B = *(pt*)b;
    pt O;O.x = 0,O.y = 0;
    long long disA = manhatanDistance(A,O);
    long long disB = manhatanDistance(B,O);
    if(disA!=disB){
        return disB-disA;
    }
    else if(A.x!=B.x){
        return A.x-B.x;
    }
    else{
        return A.y-B.y;
    }
}

long long P1ToP2Step(pt P1, pt P2){
    long long step = 0;
    long long dx = myabs(P1.x,P2.x), dy = myabs(P1.y,P2.y);
    if((dx+dy)%2==0){
        return 0;
    }
    while((dx!=0)&&(dy!=0)){

    }

}

int main()
{
    int n = 0;
    scanf("%d",&n);
    pt p[n];memset(p,0,n*sizeof(pt));
    for(int i = 0;i<n;i++){
        scanf("%lld%lld",&p[i].x,&p[i].y);
    }
    qsort(p,n,sizeof(p[0]),cmp);

    long long firstDis = manhatanDistance(p[0],p[1]);
    long long res = 0;
    //

    //for(int i = 0;i<n-1;i++){
    //    long long curStep = P1ToP2Step(p[i],p[i+1]);
    //    if(curStep == 0){
    //        break;
    //    }
    //    else{
    //        res+=curStep;
    //    }
    //}
    long long ans = 0;
    for(int i = 0; i < n-1; i++){
        long long x = p[i].x;
        long long y = p[i].y;
        unsigned long long dx = myabs(p[i].x,p[i+1].x), dy = myabs(p[i].y,p[i+1].y);
        while(1){
            if(dx == 0 && dy == 0) break;
            if(dx+dy == 1){
                ans++;
                break;
            }
            if(dx%2 == dy%2){
                printf("%lld\n",manhatanDistance(p[0],p[1]));
                printf("%lld\n",ans);
                return 0;
            }
            ans++;
            if(dx%2) dx^=dy^=dx^=dy;
            dx/=2;
            unsigned long long t1 = (dy-1)/2;
            unsigned long long t2 = (dy+1)/2;
            if(dx%2 == t1%2) dy = t2;
            else dy = t1;
        }
    }


    //printf("1to2: %lld\n",firstDis);
    //for(int i = 0;i<n;i++){
    //    printf("%d: %lld,%lld\n",i,p[i].x,p[i].y);
    //}
    printf("%lld\n",manhatanDistance(p[0],p[1]));
    printf("%lld",ans);
    return 0;
}
