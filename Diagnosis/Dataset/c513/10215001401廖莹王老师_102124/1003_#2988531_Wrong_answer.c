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
    if(d1.number!=d2.number){if(d1.number>d2.number)return -1;else return 1;}
    else {if(d1.a>d2.a)return 1;else return -1;}
}

int main()
{
    int k,i;
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
         int l,j,n,d;
    struct data p[10000];
    scanf("%d",&n);
    for(l=0;l<n;l++)
    {
        scanf("%lld",&p[l].a);
        d=1;p[l].number=0;
        for(j=0;j<64;j++)
        {if((p[l].a&d)!=0){p[l].number++;}d=d<<1;}
    }
    qsort(p,n,sizeof(p[0]),comp);
        printf("case #%d:\n",i);
    for(l=0;l<n;l++)

    {printf("%lld ",p[l].a);}
    printf("\n");



    }
    return 0;
}

