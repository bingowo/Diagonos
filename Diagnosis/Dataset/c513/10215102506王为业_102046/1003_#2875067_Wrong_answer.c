#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long arr[10008];
int cmp(long long*x,long long*y)
{
    int onex=0,oney=0;
    for(int i=0;i<64;++i){
        if((*x)&(1<<i))
            ++onex;
        if((*y)&(1<<i))
            ++oney;
    }
    if(onex==oney){
        return *x>*y?1:-1;
    }else{
        return onex>oney?-1:1;
    }
}
int main()
{
    int T,N;
    scanf("%d",&T);
    for(int iT=0;iT<T;++iT){
        printf("case #%d:\n",iT);
        scanf("%d",&N);
        for(int iN=0;iN<N;++iN){
            scanf("%lld",&arr[iN]);
        }
        qsort(arr,N,sizeof(long long),cmp);
        for(int iN=0;iN<N-1;++iN){
            printf("%lld ",arr[iN]);
        }printf("%lld\n",arr[N-1]);
    }

    return 0;
}
