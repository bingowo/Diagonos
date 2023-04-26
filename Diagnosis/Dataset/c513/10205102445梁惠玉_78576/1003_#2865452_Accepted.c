#include <stdio.h>

struct data{
long long int a;
int number;};

int cmp(const void*a, const void*b)
{
    struct data x,y;
    x=*((struct data *)a);
    y=*((struct data *)b);
    if(x.number!=y.number)
    {
        return y.number-x.number;
    }
    else{
        if(x.a>y.a) return 1;
        else return -1;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int q=0;q<T;q++)
    {
        printf("case #%d:\n",q);
        int N;
        scanf("%d",&N);
        struct data p[N];
        for(int i=0;i<N;i++)
        {
            scanf("%lld",&p[i].a);
            long long int d=1;
            p[i].number=0;
            for(int t=0;t<64;t++)
            {
                if(p[i].a&d){
                    p[i].number++;
                }
                d=d<<1;
            }
        }
        qsort(p,N,sizeof(p[0]),cmp);
        int i;
        for( i=0;i<N-1;i++)
        {
            printf("%lld ",p[i].a);
        }
        printf("%lld\n",p[i].a);
    }
    return 0;
}

