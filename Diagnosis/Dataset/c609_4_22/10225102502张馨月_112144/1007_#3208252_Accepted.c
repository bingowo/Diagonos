#include<stdio.h>
#include<stdlib.h>
struct px
{
    long long int a;
    int num;
};

int cmp(const void*a,const void*b)
{
    struct px d1,d2;
    d1=*((struct px*)a);
    d2=*((struct px*)b);
    if(d1.num!=d2 .num) return d2.num-d1.num;
    else
    {
        if(d1.a>d2.a) return 1;
        else return -1;
    }
}

int main()
{
    int t,n;
    struct px p[10000];
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);

        for(int i=0;i<n;i++)
        {
            scanf("%lld",&p[i].a);
            p[i].num=0;
            long long d = 1;
            for(int r=0;r<64;r++)
            {
                if(p[i].a&d) p[i].num++;
                d=d<<1; //d每次右移一位看看每一位是否为1
            }
        }
        qsort(p,n,sizeof(p[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<n;j++)
            printf("%lld ",p[j].a);
        printf("\n");
    }
    return 0;
}