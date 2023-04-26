#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a,const void* b)
{
    int a1=0,b1=0;
    long long x=*(long long *)a;
    long long y=*(long long *)b;
    long long x1=x;
    long long y1=y;
    if(x>=0)
    {
        while(x/2>0)
        {
            a1=x%2+a1;
            x=x/2;
        }
        a1=a1+x;
    }
    else if(x<0)
    {
        x=-x-1;
        while(x/2>0)
        {
            a1=x%2+a1;
            x=x/2;
        }
        a1=64-a1-x;

    }
    if(y>=0)
    {
        while(y/2>0)
        {
            b1=y%2+b1;
            y=y/2;
        }
        b1=b1+y;
    }
    else if(y<0)
    {
        y=-y-1;
        while(y/2>0)
        {
            b1=y%2+b1;
            y=y/2;
        }
        b1=64-b1-y;

    }
    if(a1>b1) return -1;
    else if(a1<b1) return 1;
    else
    {
        if(x1>y1) return 1;
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
        long long *chushi;
        chushi=(long long *)malloc(sizeof(long long)*N);
        for(int j=0;j<N;j++)
        {
            scanf("%lld",&chushi[j]);
        }
        qsort(chushi,N,sizeof(long long),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<N;j++)
        {
            printf("%lld ",chushi[j]);
        }
        printf("\n");
    }
}

