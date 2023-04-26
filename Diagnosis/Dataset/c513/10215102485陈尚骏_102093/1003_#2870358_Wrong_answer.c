#include <stdio.h>
#include <stdlib.h>

struct data{
  long long a;
  int num;
};

int cmp(const void *a,const void *b)
{
    struct data d1,d2;
    d1=*((struct data*)a);
    d2=*((struct data*)b);
    if(d1.num!=d2.num)
        return d2.num-d1.num;
    else
    {
        if(d1.a>d2.a)
            return 1;
        else
            return -1;
    }
}
int main()
{
    int T;
    int i,k=0;
    scanf("%d",&T);
    while(T--)
    {
        int N;
        struct data p[10000];
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            scanf("%lld",&p[i].a);
            int d=1;
            p[i].num=0;
            for(int j=0;j<64;j++)
            {
                if(p[i].a&d==1)
                {
                    p[i].num++;
                    d=d<<1;
                }
            }
        }
        printf("case #%d:\n",k++);
        for(i=0;i<N-1;i++)
            printf("%lld ",p[i].a);
        printf("%lld\n",p[i].a);
    }
    return 0;
}
