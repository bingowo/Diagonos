#include <stdio.h>
#include <stdlib.h>

struct cylinder
{
    int r,h;
    long long product;
};

int cmp(const void* a,const void* b)
{
    struct cylinder x=*((struct cylinder*)a);
    struct cylinder y=*((struct cylinder*)b);
    if(x.product>y.product)return -1;
    else
        return 1;
}

long long Max(long long a,long long b)
{
    if(a>=b)return a;
    else
        return b;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    struct cylinder a[1000];
    for(int i=0;i<n;i++){
        //a[i].r=0;a[i].h=0;a[i].product=0;
        scanf("%d%d",&a[i].r,&a[i].h);
        a[i].product = (long long)a[i].r*a[i].h;
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        struct cylinder ax[1000];

        int k=0;
        for(int j=0;j<n;j++){
            if(j != i && a[j].r<=a[i].r)ax[k++] = a[j];
        }
        qsort(ax,k,sizeof(ax[0]),cmp);
        long long area=0;
        if(k != 0 && k>=m-1){
            for(int cnt=0;cnt<m-1;cnt++)area += ax[cnt].product;
        }
        ans = Max(ans,area*2+(long long)a[i].r*a[i].r+2*a[i].product);
    }
    printf("%lld",ans);
    return 0;
}
