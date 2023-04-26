//sort\1027.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

//#define LOCAL
#define TRUE 1
#define FALSE 0
struct polar{
    double plen,angle;
};
typedef struct polar pcs;
pcs arr[1010];
int cmp(pcs*x,pcs*y)
{
    double tem=x->angle-y->angle;
    if(-0.00001<tem&&tem<0.00001){
        tem=x->plen-y->plen;
        return tem>0?-1:1;
    }else{
        return tem>0?1:-1;
    }
}
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int T;
    scanf("%d",&T);
    for(int iT=0;iT<T;++iT){
        printf("case #%d:\n",iT);
        int N;
        double temx,temy;
        scanf("%d",&N);
        for(int iN=0;iN<N;++iN){
            scanf("%lf%lf",&temx,&temy);
            arr[iN].plen=sqrt(temx*temx+temy*temy);
            arr[iN].angle=atan2(temy,temx);
            if(arr[iN].angle<0)arr[iN].angle+=2*3.141592653589793;
        }
        qsort(arr,N,sizeof(arr[0]),cmp);
        for(int iN=0;iN<N;++iN){
            printf("(%.4lf,%.4lf)\n",arr[iN].plen,arr[iN].angle);
        }
    }
}
