#include <stdio.h>
#include <stdlib.h>

struct data
{
    long long int a;
    int number;
};
int comp(const void *a,const void *b)
{
    struct data d1,d2;
    d1=*((struct data *)a);
    d2=*((struct data *)b);
    if(d1.number!=d2.number) return d2.number-d1.number;
    else {if(d1.a>d2.a)return 1;else return -1;};
}
void dh()
{
    int i,j,n,d;
    struct data p[1000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&p[i].a);
        d=1;p[i].number=0;
        for(j=0;j<64;j++)
        {if((p[i].a&d)!=0)p[i].number++;d=d<<1;}
    }
    qsort(p,n,sizeof(p[0]),comp);
    for(i=0;i<n;i++)
    {printf("%lld ",p[i].a);}
}
int main()
{
    int k,i;
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
         printf("case #%d:\n",i);

        dh();


    }
    return 0;
}

