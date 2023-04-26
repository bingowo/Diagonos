#include <stdio.h>
#include <stdlib.h>

typedef struct {int r; long long base,side;} cylinder;

int cmp(const void* a,const void* b)
{
    cylinder* c = (cylinder*)a; cylinder* d = (cylinder*)b;
    return (d->side-c->side>0)? 1: -1;
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
        int cnt = 0;
        for (int j=0;j<n;j++)
        {
            if (j==i) continue;
            temp += a[j].side;
            cnt++;
            if (cnt==m-1) break;
        }
        if (temp>max) max = temp;
    }
    printf("%lld\n",max);
    system("pause");
    return 0;
}