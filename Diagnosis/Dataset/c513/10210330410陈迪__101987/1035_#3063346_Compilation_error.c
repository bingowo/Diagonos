#include <stdio.h>
#include <stdlib.h>

struct cylinder
{
    int radius, height;
    long long product;
};

int cmp(const void *pa, const void *pb)
{
    struct cylinder* a = (struct cylinder*)pa;
    struct cylinder* b = (struct cylinder*)pb;
    if(a->product > b->product) return -1;
    else return 1;
}

int main()
{
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);
    struct cylinder a[1000];
    for(int i=0; i<n; i++)
    {
        scanf("%d%d", &a[i].radius, &a[i].height);
        a[i].product = (long long)a[i].radius*a[i].height;
    }
    long long ret = 0;
    for(int i=0; i<n; i++)
    {
        struct cylinder ax[1000];
        int k=0;
        for(int j=0; j<n; j++)
        {
            if(j!=i && a[j].radius<=a[i].radius) ax[k++] = a[j];
        }
        qsort(ax,k,zieof(ax[0]),cmp);
        long long are = 0;
        if(k!=0 && k>=m-1)
        {
            for(int cnt=0; cnt<m-1; cnt++)
            {
                area += ax[cnt].product;
            }
        }
        if( ret < ( 2*a[i].product + area*2 + (long long)a[i].radius*a[i].radius )) ret = 2*a[i].product + area*2 + (long long)a[i].radius*a[i].radius;
    }
    printf("%lld", ret);
    return 0;
}
