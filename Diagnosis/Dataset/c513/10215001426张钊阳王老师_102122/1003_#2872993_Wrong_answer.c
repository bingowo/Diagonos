#include <stdio.h>
#include <stdlib.h>
struct data
{
    long long int a;    //整数
    int number;  //64位二进制补码表示中1的位数
};
int cmp(const void *a,const void *b)
{
    struct data d1,d2;
    d1=*((struct data*)a);
    d2=*((struct data*)b);
    if(d2.number!=d1.number)
         return d2.number-d1.number;
    else
    {
         if(d1.a>d2.a) return 1;
         else return -1;
    }
}
int main()
{
    int m;
    scanf("%d",&m);
    for(int s=0;s<m;s++)
    {
        int t,i,n;
        int d=1,number=0;
        struct data p[10000];
        scanf("%d",&n);
        for(i=0;i<n;i++)
    {
        scanf("%lld",&p[i].a);
        d=1;p[i].number=0;
        for(t=0;t<64;t++)
        {
            if(p[i].a&d) p[i].number++;
            d=d<<1;
        }
        qsort(p,n,sizeof(p[0]),cmp);
        printf("case #%d:\n",s);
        for(i=0;i<n-1;i++)
            printf("%lld ",p[i].a);
        printf("%lld\n",p[i].a);
    }

    return 0;
}
}
