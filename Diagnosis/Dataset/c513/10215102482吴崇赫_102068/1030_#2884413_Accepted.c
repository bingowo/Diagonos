#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 10005

int getGao(long long _n)
{
    long long n=_n;
    while(1){
        if(n/10==0)break;
        n/=10;
    }
    n=n>0?n:-n;
    return n;
}

int cmp(const void* a,const void* b)
{
    long long la=*(long long*)a;
    long long lb=*(long long*)b;
    if(getGao(la)!=getGao(lb))return getGao(la)<getGao(lb)?1:-1;
    else return la>lb?1:-1;
}

int main()
{
    int T,x=0;
    scanf("%d\n",&T);
    while(x<T){
        long long a[N]={0};
        int n;scanf("%d\n",&n);
        for(int i=0;i<n;++i)scanf("%lld",&a[i]);
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",x++);
        for(int i=0;i<n;++i)printf("%lld%c",a[i],i==n-1?'\n':' ');
    }
    return 0;
}
