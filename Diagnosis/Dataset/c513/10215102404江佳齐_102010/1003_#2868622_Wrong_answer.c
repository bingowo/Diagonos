#include <stdio.h>
#include <stdlib.h>

struct data
{
    long long int a;
    int num;
};
int cmp(const void *a,const void *b)
{
    struct data d1,d2;
    d1=*((struct data *)a);
    d2=*((struct data *)b);
    if(d1.num!=d2.num) return d2.num-d1.num;
    else
    {
        if(d1.a>d2.a) return 1;
        else return -1;
    }
}

int main()
{
    int t,n;
    struct data p[10000];
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);
        printf("case #%d:\n",i);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&p[i].a);
            p[i].num=0;
            for(int r=0;r<64;r++)
            {
                int d=1;
                if(p[i].a&d) p[i].num++;
                d=d<<1;
            }
        }
        qsort(p,n,sizeof(p[0]),cmp);
        for(int j=0;j<n;j++) printf("%lld\n",p[j].a);
    }

    return 0;
}

