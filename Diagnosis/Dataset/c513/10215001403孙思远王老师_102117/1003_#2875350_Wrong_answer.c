#include <stdio.h>
#include <stdlib.h>

struct mm
{
    int a;
    int b;
};

int count(int a);
int cmp(const void *a,const void *b);

int main()
{
    int N,T,i,j;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        scanf("%d",&N);
        struct mm m[10000];
        int ii;
        for(ii=0;ii<N;ii++)
        {
            scanf("%d",&m[ii].a);
            m[ii].b=count(m[ii].a);
        }
        qsort(m,N,sizeof(m[0]),cmp);
        for(j=0;j<N-1;j++)
        {
            printf("%d",m[j].a);
            printf(" ");
        }
        printf("%d\n",m[j].a);
    }
    return 0;
}

int cmp(const void *pa,const void *pb)
{
    struct mm d1,d2;
    d1=*((struct mm *)pa);
    d2=*((struct mm *)pb);
    if(d2.b!=d1.b)
         return d2.b-d1.b;
    else
    {    if(d1.a>d2.a) return 1;
         else return -1;
    }
}
int count(int a)
{
    int j=1,num=0;
    for(int i=0;i<64;i++)
    {
        if((a|j)==a)num++;
        j=j<<1;
    }
    return num;
}
