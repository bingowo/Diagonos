#include <stdio.h>
#include <stdlib.h>

long long numof(int x)
{
    long long re=0;
    for(int i=0;i<64;i++)
    {
        if((x&1)==1) re++;
            x=x>>1;
    }

    return re;
}

int cmp(const void*p,const void*q)
{
    long long* p1=(long long*)p;
    long long* q1=(long long*)q;
    long long rp=numof(*p1);
    long long rq=numof(*q1);
    if(rp==rq)
    {
        if(*p1<*q1) return -1;
        else return 1;

    }
    else if(rp>rq) return -1;
    else return 1;

}

int main()
{
    int t,i,j,k;

    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        //printf("ceshi n=%d\n",n);
        long long *d=(long long*)malloc(n*sizeof(long long));
        for(j=0;j<n;j++) scanf("%lld",&d[j]);
        qsort(d,n,sizeof(long long),cmp);
         printf("case #%d:\n",i);
        for(k=0;k<n;k++)
        {
            printf("%lld ",d[k]);
        }
        printf("\n");
        free(d);
    }
    return 0;
}
