#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
    double x;
    double y;
    double a;
    double b;
} zb;
int cmp(const void *a,const void *b)
{
    zb* a0=(zb*)a;
    zb* b0=(zb*)b;
    if(a0->b!=b0->b)
        return a0->b-b0->b;
    return b0->a-a0->a;
}
int main()
{
    zb a0[1000];
    int t,n,i,j;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        for(j=0;j<n;j++){
            scanf("%f%f",&a0[j].x,a0[j].y);
            a0[j].a=sqrt(a0[j].x*a0[j].x+a0[j].y*a0[j].y);
            a0[j].b=atan(a0[j].y/a0[j].x);
        }
        qsort(a0,n,sizeof(a0[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<n;j++)
            printf("(%.4f,%.4f)\n",a0[j].a,a0[j].b);
    }
    return 0;
}
