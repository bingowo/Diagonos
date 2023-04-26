#include<stdio.h>
#include<stdlib.h>

struct data
{
    long long a;
    int number;
};


int cmp(const void*a,const void*b)
{
    struct data d1,d2;
    d1=*((struct data *)a);
    d2=*((struct data *)b);
    if(d2.number!=d1.number)
    return d2.number-d1.number;
    else
    {
        if(d1.a>d2.a)return 1;
        else return -1;
    }
}

int main()
{
    int i,d,t,N,n,k,j;
    struct data p[10000];
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d",&n);k=0;
        while(k++<n)
        {
        scanf("%lld",&p[k-1].a);
        d=1;p[k-1].number=0;
        for(t=0;t<200;t++)
        {
            if(p[k-1].a&d)p[k-1].number++;
            d=d<<1;
        }}
        printf("case #%d:\n",i);
        qsort(p,n,sizeof(struct data),cmp);
    for(j=0;j<n-1;j++)printf("%lld ",p[j].a);
    printf("%lld\n",p[j].a);
    }


}
