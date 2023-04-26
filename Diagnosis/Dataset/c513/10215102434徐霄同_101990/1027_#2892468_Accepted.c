#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
    double x;
    double y;
    double a;
    double b;
} zb;
int cmp(const void *aa,const void *bb)
{
    zb* a0=(zb*)aa;
    zb* b0=(zb*)bb;
    if(a0->b>b0->b)
        return 1;
    else if(a0->b<b0->b)
        return -1;
    else if(b0->a>a0->a)
        return 1;
    else
        return -1;
}
int main()
{
    zb a0[1000];
    int t,n,i,j;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        for(j=0;j<n;j++){
            scanf("%lf%lf",&a0[j].x,&a0[j].y);
            a0[j].a=sqrt(a0[j].x*a0[j].x+a0[j].y*a0[j].y);
            a0[j].b=atan(a0[j].y/a0[j].x);
            if(a0[j].x<0)
                a0[j].b+=acos(-1);
            else if(a0[j].y<0)
                a0[j].b+=acos(-1)*2;
        }
        qsort(a0,n,sizeof(a0[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<n;j++)
            printf("(%.4f,%.4f)\n",a0[j].a,a0[j].b);
    }
    return 0;
}
