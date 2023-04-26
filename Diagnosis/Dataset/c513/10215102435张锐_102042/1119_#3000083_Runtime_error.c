#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int dd;
    int v;
    double t;
}che;
int cmp(const void *a,const void *b)
{
    che *s1=(che*)a,*s2=(che*)b;
    if(s1->t<s2->t) return 1;
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
        p[i].t=(double)(d-p[i].dd)/p[i].v;
    }
    qsort(p,n,sizeof(p[0]),cmp);
    printf("%.6lf",d/p[0].t);
    return 0;
}
