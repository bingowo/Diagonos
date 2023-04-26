#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
    double s;
    double v;
    double max;
}car;
int cmp(const void *a,const void *b )
{
    car*p1=(car *)a;
    car*p2=(car*)b;
    return p1->max-p2->max;


}
int main()
{
    int d;
    scanf("%d",&d);
    int n;
    scanf("%d",&n);
    car a[n];
    for(int i=0;i<n;i++){
        scanf("%lf %lf",&a[i].s,&a[i].v);
        double cha=d-a[i].s;
        double t=cha/a[i].v;
        a[i].max=d/t;
    }
    qsort(a,n,sizeof(a[0]),cmp);
    printf("%.6f",a[0].max);
}
