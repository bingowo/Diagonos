#include <stdio.h>
#include <stdlib.h>

int fv(long long a)
{
    if(a<0) a=-a;
    while(a/10!=0)
        a/=10;
    return a;
}

int cmp(const void* a,const void* b)
{
    long long aa=*(long long *)a,bb=*(long long*)b;
    if(fv(aa)!=fv(bb)) return fv(bb)-fv(aa);
    else if(aa>bb) return 1;
    else if(aa<bb) return -1;
    return 0;
}


int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N=0;
        long long a[10000];
        scanf("%d",&N);
        for(int i=0;i<N;i++)
            scanf("%lld",&a[i]);
        qsort(a,N,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int i=0;i<N;i++)
            printf("%lld%c",a[i],i!=N-1?' ':'\n');

    }
    return 0;
}
