#include <stdio.h>
typedef struct
{
    int ai;
    int bi;
    int ao;
    int bo;
    int as;
    int bs;
}P;

int main()
{
    int a,b,n,m,x,i;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    P p[25];
    p[1].ai=1;p[1].bi=0;p[1].ao=0;p[1].bo=0;p[1].as=1;p[1].bs=0;
    p[2].ai=0;p[2].bi=1;p[2].ao=0;p[2].bo=1;p[2].as=1;p[2].bs=0;
    for(i=3;i<=n;i++)
    {
        p[i].ai=p[i-1].ai+p[i-2].ai;
        p[i].bi=p[i-1].bi+p[i-2].bi;
        p[i].ao=p[i-1].ai;
        p[i].bo=p[i-1].bi;
        p[i].as=p[i-1].as-p[i].ao+p[i].ai;
        p[i].bs=p[i-1].bs-p[i].bo+p[i].bi;
    }
    b=(m-p[n-1].as*a)/p[n-1].bs;
    printf("%d",p[x].as*a+p[x].bs*b);
    return 0;
}
