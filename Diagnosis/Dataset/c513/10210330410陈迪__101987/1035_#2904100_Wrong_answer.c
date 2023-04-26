#include <stdio.h>
#include <stdlib.h>

long long Max(long long a, long long b)
{
    return a>b ? a:b;
}

struct cylinder {
    int radius, height;
    long long product;
};
struct cylinder a[1000];

int cmp(const void*a, const void*b)
{
   return ((struct cylinder*)a)->product > ((struct cylinder*)b)->product ? -1:1;
}

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].radius, &a[i].height);
        a[i].product = (long long)a[i].radius * a[i].height;
    }
    long long ans=0;
    struct cylinder ax[1000];
    for(i=0;i<n;i++)
    {
        int k=0;
        for(int j=0;j<n;j++) if(j!=i&&a[j].radius<=a[i].radius) ax[k++]=a[j];
        qsort(ax,k,sizeof(ax[0]),cmp);
        long long area = 0;
        if(k!=0&&k>m-1)
        {
            for(int cnt=0;cnt<m-1;cnt++) area+=ax[cnt].product;
        }
        ans = Max(ans,area*2+(long long)a[i].radius*(long long)a[i].radius+2*a[i].product);
    }
    printf("%lld",ans);
    return 0;
}
