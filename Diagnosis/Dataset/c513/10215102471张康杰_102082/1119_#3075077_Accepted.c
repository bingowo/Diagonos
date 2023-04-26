#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double d,v,t;
}CAR;

int cmp(const void*a,const void*b)
{
    CAR *st1 = (CAR*)a,*st2 = (CAR*)b;
    return st1->d - st2->d;
}

double max(double t1,double t2)
{
    if(t1 < t2)
        return t2;
    else
        return t1;
}

int main()
{
    double d;
    int n,i;
    scanf("%lf",&d);
    scanf("%d",&n);
    CAR*cars = (CAR*)malloc(n * sizeof(CAR));
    for(i = 0;i < n;i++)
        scanf("%lf %lf",&cars[i].d,&cars[i].v);
    qsort(cars,n,sizeof(cars[0]),cmp);
    cars[0].t = (d - cars[0].d) / cars[0].v;
    for(i = 1;i < n;i++)
    {
        cars[i].t = max(cars[i - 1].t,(d - cars[i].d) / cars[i].v);
    }
    printf("%.6lf",d / cars[n - 1].t);
    return 0;
}
