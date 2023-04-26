#include <stdio.h>
#include <stdlib.h>

struct data
{
    long long a;
    int num;
};

int compare(const void*a,const void*b)
{
    struct data data1,data2;
    data1=*((struct data*)a);
    data2=*((struct data*)b);
    if(data2.num!=data1.num)
    {
        return data2.num-data1.num;
    }
    else
    {
        if(data1.a>data2.a)
            return 1;
        else return -1;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        struct data a[10000];
        for(int j=0;j<N;j++)
        {
            scanf("%lld",&a[j].a);
            a[i].num=0;
            long long y=a[j].a;
            while(y)
            {
                y=y&(y-1);
                a[i].num++;
            }
        }
        qsort(a,N,sizeof(a[0]),compare);
        printf("case #%d:\n",i);
        int j=0;
        for(;j<N-1;j++)
        {
            printf("%lld ",a[j].a);
        }
        printf("%lld\n",a[j].a);
    }
    return 0;
}
