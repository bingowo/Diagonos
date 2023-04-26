#include <stdio.h>
#include <stdlib.h>
struct num{
    long long value;
    int highvalue;
};
typedef struct num dig;
dig arr[10100];

int cmp(dig*x,dig*y)
{
    if(x->highvalue==y->highvalue)
        return x->value>y->value?1:-1;
    else
        return x->highvalue>y->highvalue?-1:1;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int iT=0;iT<T;++iT){
        printf("case #%d:\n",iT);
        int N;
        scanf("%d",&N);
        memset(arr,0,N*sizeof(arr[0]));
        for(int iN=0;iN<N;++iN){
            scanf("%lld",&arr[iN].value);
            long long tem=arr[iN].value;
            if(tem<0)tem=-tem;
            long long res=tem;
            //quickly
            if(tem>100000000000000000)tem/=100000000000000000;
            if(tem>1000000000000000)tem/=1000000000000000;
            if(tem>10000000000000)tem/=10000000000000
            if(tem>100000000000)tem/=100000000000;
            if(tem>100000000)tem/=100000000;
            if(tem>1000000)tem/=1000000;
            if(tem>10000)tem/=10000;
            if(tem>100)tem/=100;
            while(tem!=0){
                res=tem%10;
                tem/=10;
            }
            arr[iN].highvalue=res;
            qsort(arr,N,sizeof(arr[0]),cmp);
        }
        for(int iN=0;iN<N-1;++iN){
            printf("%lld ",arr[iN].value);
        }printf("%lld\n",arr[N-1].value);

    }
}
