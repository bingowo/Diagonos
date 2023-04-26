#include <stdio.h>
#include <stdlib.h>

typedef struct {int r; long long base,side;} cylinder;

int cmp(const void* a,const void* b)
{
    cylinder* c = (cylinder*)a; cylinder* d = (cylinder*)b;
    return d->r-c->r;
}

main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    cylinder a[1001];
    for (int i=0;i<n;i++)
    {
        int h,r;
        scanf("%lld %lld",&r,&h);
        a[i].r = r, a[i].base = r*r, a[i].side = 2*r*h;
    }
    qsort(a,n,sizeof(a[0]),cmp);
    long long max = 0;
    for (int i=0;i<=n-m;i++)
    {
        long long temp = a[i].base + a[i].side;
        for (int j=1;j<m;j++) temp += a[i+j].side;
        if (temp>max) max = temp;
    }
    printf("%lld\n",max);
    return 0;
}