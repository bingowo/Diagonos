#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int noe(long long a)
{
    long long x=1;
    int res=0;
    for(int i=0;i<64;i++)
    {
        if((a&x)==1)
            res++;
        a=a>>1;
    }
    return res;
}
int compar(const void *a,const void *b)
{
    long long *p,*q;
    p=(long long*)a;
    q=(long long*)b;
    if(noe(*p)>noe(*q))
        return -1;
    else if(noe(*p)<noe(*q))
        return 1;
    else
    {
        if(*p<*q)
            return -1;
        else
            return 1;
    }
}
int main()
{
    int T,N,x;
    long long *a;
    scanf("%d",&T);
    for(x=0;x<T;x++)
    {
        printf("case #%d:\n",x);
        scanf("%d",&N);
        a=(long long*)malloc(N*sizeof(long long));
        for(int i=0;i<N;i++)
            scanf("%lld",&a[i]);
        qsort(a,N,sizeof(long long),compar);
        for(int i=0;i<N;i++)
            printf("%lld ",a[i]);
        printf("\n");
        free(a);
    }
    return 0;
}
