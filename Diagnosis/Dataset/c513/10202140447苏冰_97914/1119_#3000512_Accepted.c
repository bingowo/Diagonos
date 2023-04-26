#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int cmp(const void*_a,const void*_b)
{
    double* a=(double*)_a;
    double* b=(double*)_b;
    return (*a>*b?1:-1);
}
int main()
{
    double d;
    scanf("%lf",&d);
    int n;
    scanf("%d",&n);
    double a[1000];
    int s,v;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&s,&v);
        a[i]=d*v/(d-s);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    printf("%.6f\n",a[0]);
    return 0;
}
