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
    printf("x=%lf y=%lf\n",d->x,d->y);
    double a=(d->x)*(d->x)+(d->y)*(d->y);
    while (fabs(temp-p)>=1e-6)
    {
        temp=p;
        p=(a-p*p*1.0)/(2.0*p)+p*1.0;
    }
    // double b=(d->y)/(d->x);
    r=atan(d->y/d->x);
    d->x=p;
    printf("%lf",d->x); 
    d->y=(r>=0?r:2.0*PI+r);
    printf(" %lf ",d->y); 
}

int main()
{
    int T,i,j,n;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d",&n);
        printf("case #%d:\n",i-1);
        node *dot=(node*)malloc(sizeof(node)*1000);
        for (j=0;j<n;j++)
        {
        	
            scanf("%lf%lf",&dot[j].x,&dot[j].y);
            itob(dot+j);
            
        }
        qsort(dot,n,sizeof(dot[0]),cmp);
        for(j=0;j<n;j++)
        {
            printf("(%0.4lf,%0.4lf)\n",dot[j].x,dot[j].y);
        }
        free(dot);
    }
    return 0;
}