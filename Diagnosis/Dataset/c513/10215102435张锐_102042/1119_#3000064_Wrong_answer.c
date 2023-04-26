#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int dd;
    int v;
}che;
int cmp(const void *a,const void *b)
{
    che *s1=(che*)a,*s2=(che*)b;
    if(s1->v>s2->v) return 1;
    else if(s1->v==s2->v)
    {
        if(s1->dd<s2->dd) return 1;
    }
    else return -1;
}
int main()
{
    int d;
    scanf("%d",&d);
    int n;
    scanf("%d",&n);
    che *p=(che*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&p[i].dd,&p[i].v);
    }
    qsort(p,n,sizeof(p[0]),cmp);
    double s=(double)(d-p[0].dd);
    printf("%.6lf",d/(s/p[0].v));
    return 0;
}