#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int d,v;
    double t;
}CAR;

int cmp(const void*a,const void*b)
{
    CAR *st1 = (CAR*)a,*st2 = (CAR*)b;
    return st1->d - st2->d;
}

double max(double t1,double t2)
{
    if(t1 - t2 > 0.000001)
        return t1;
    else
        return t2;
}

int main()
{
    int d,n,i;
    scanf("%d",&d);
    scanf("%d",&n);
    CAR*cars = (CAR*)malloc(n * sizeof(CAR));
    for(i = 0;i < n;i++)
        scanf("%d %d",&cars[i].d,&cars[i].v);
    qsort(cars,n,sizeof(cars[0]),cmp);
    cars[0].t = (d - cars[0].d) / cars[0].v;
    for(i = 1;i < n;i++)
    {
        cars[i].t = max(cars[i - 1].t,(d - cars[i].d) / cars[i].v);
    }
    printf("%.6lf",d / cars[n - 1].t);
    return 0;
}
