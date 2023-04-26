#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int cmp(const void*a, const void*b);

int main()
{
    int T; scanf("%d",&T);
    int j;
    for(j=0;j<T;j++)
    {
        int N;scanf("%d",&N);
        long long *a;
        a = (long long*)malloc(N*sizeof(1LL));
        int i;
        for(i=0;i<N;i++) scanf("%lld",a+i);
        qsort(a,N,sizeof(1LL),cmp);
        printf("case #%d:\n",j);
        for(i=0;i<N;i++) printf("%lld ",*(a+i));
        printf("\n");
        free(a);
    }
    return 0;
}

int cmp(const void*a, const void*b)
{
    int bit(long long), abit, bbit;
    abit = bit(*(long long*)a);
    bbit = bit(*(long long*)b);
    if(abit==bbit && *(long long*)a >= *(long long*)b) return 1;
    else if(abit==bbit && *(long long*)a < *(long long*)b) return -1;
    else return bbit - abit;
}

int bit(long long p)
{
    int nbit,i;
    nbit = 0;
    for(i=0;i<64;i++) nbit += ((1LL<<i)&p)==0 ? 0:1;
    return nbit;
}
