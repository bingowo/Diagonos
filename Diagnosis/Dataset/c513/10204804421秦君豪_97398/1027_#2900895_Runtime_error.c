#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<math.h>
#include<stdlib.h>
#define PI 3.1415926
typedef struct 
{
    double x,y;

}node;

int cmp(const void*a,const void*b)
{
    node* a1=(node*)a;
    node* b1 = (node*)b;
    if ((a1->y)<(b1->y)) return -1;
    else if ((a1->y)>(b1->y)) return 1;
    else return ((a1->x)>(b1->x)?-1:1);
}
void itob(node* d)
{
    double p=1,r,temp=2;
    double a=(d->x)*(d->x)+(d->y)*(d->y);
    while (fabs(temp-p)>=1e-6)
    {
        temp=p;
        p=(a-p*p*1.0)/(2.0*p)+p*1.0;
    }
    // double b=(d->y)/(d->x);
    r=atan2(d->x,d->y);
    d->x=p;
    d->y=(r>=0?r:PI+r);
}

int main()
{
    int T,i,j,n;
    node *dot;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d",&n);
        printf("case #%d:\n",i-1);
        for (j=0;j<n;j++)
        {
            scanf("%lf%lf",&(dot+j)->x,&(dot+j)->y);
            itob(dot+j);
        }
        qsort(dot,n,sizeof(dot[0]),cmp);
        for(j=0;j<n;j++)
        {
            printf("(%0.4lf,%0.4lf)\n",(dot+j)->x,(dot+j)->y);
        }
    }
    system("pause");
    return 0;
}