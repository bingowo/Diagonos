#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
int cmp(const void *a, const void *b)
{
    double x=*(double*)a,y=*(double*)b;
    if(x>y)
        return -1;
    else
        return 1;
}
int main()
{
    double d;
    int n;
    scanf("%lf%d",&d,&n);
    double a[n];
    for(int i=0;i<n;i++)
    {
        double d1,t;
        scanf("%lf%lf",&d1,&t);
        a[i]=(d-d1)/t;
    }
    qsort(a,n,sizeof(double),cmp);
    printf("%.6f",d/a[0]);
    return 0;
}
