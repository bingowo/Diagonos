#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

typedef struct{double dis;double v;}car;

int cmp(const void*a1,const void*a2)
{
    car a=*(car*)a1;
    car b=*(car*)a2;
    if(a.v!=b.v)
    {
        if(a.v>b.v) return 1;
        else return -1;
    }
    else
    {
        if(a.dis>b.dis) return 1;
        else return -1;
    }
}



int main()
{
    double d;
    scanf("%lf",&d);
    int n;
    scanf("%d",&n);
    car *a;
    a=(car*)malloc(n*sizeof(car));
    for(int i=0;i<n;i++)
    {
        scanf("%lf %lf",&a[i].dis,&a[i].v);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    double t=(d-a[0].dis)/a[0].v;
    double vmax=d/t;
    printf("%.6lf",vmax);
    return 0;
}
