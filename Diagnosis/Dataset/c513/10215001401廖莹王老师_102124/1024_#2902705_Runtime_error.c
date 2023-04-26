#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char xh[12];
    int x;
    int a[100];
    int sum;
}student;
typedef struct
{
    int n;
    int m;
    int fen[100];
    int g;
}test;
int cmp(const void *a,const void*b)
{
    student*p1,*p2;
    p1=(student*)a;
    p2=(student*)b;
    if(p1->sum!=p2->sum) return p2->sum-p1->sum;
    else return strcmp(p1->xh,p2->xh);
}
void paixu (int h)
{

        int i,k,l,count=0;
    student p[100];
    test d1;
    scanf("%d %d %d",&d1.n,&d1.m,&d1.g);
    for(i=0;i<d1.m;i++)scanf("%d",&d1.fen[i]);
    for(i=0;i<d1.n;i++)
    {
        scanf("%s %d",p[i].xh,&p[i].x);
        for(k=0;k<p[i].x;k++)
        {
            scanf("%d",&p[i].a[k]);
        }
    }
    for(i=0;i<d1.n;i++)
    {    p[i].sum=0;
        for(k=0;k<p[i].x;k++)
           {
               l=p[i].a[k]-1;
               p[i].sum=p[i].sum+d1.fen[l];
           }
    }
    qsort(p,d1.n,sizeof(p[0]),cmp);
    for(i=0;i<d1.n;i++)
    {
        if(p[i].sum>=d1.g)count++;
    }
    printf("case #%d:\n",h);
    printf("%d\n",count);
    for(i=0;i<d1.n;i++)
    {
        if(p[i].sum>=d1.g)
            printf("%s %d\n",p[i].xh,p[i].sum);
    }

}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)
    {
        paixu(h);
    }
    return 0;

}
