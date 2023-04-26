#include <stdio.h>
#include <stdlib.h>

struct cylinder
{
    int radium,height;
    long long product;
};

int cmp(const void *pa,const void *pb)
{
    struct cylinder *a=(struct cylinder*)pa;
    struct cylinder *b=(struct cylinder*)pb;
    return b->product-a->product;
}

int main()
{
    int n,m,i,j,k;
    long long area,ret=0;
    struct cylinder a[1001],ax[1000];
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a[i].radium,&a[i].height);
        a[i].product=(long long)a[i].radium*a[i].height;//记得类型转换，刚开始忘了加long long
    }
    for(i=0;i<n;i++)
    {
        k=0;
        area=0;
        for(j=0;j<n;j++)
        {
            if(i!=j&&a[i].radium>=a[j].radium)
               ax[k++]=a[j];
        }
        qsort(ax,k,sizeof(struct cylinder),cmp);
        if(k!=0&&k>=m-1)
        {
            for(j=0;j<m-1;j++)
                area=area+ax[j].product;
        }
        if(ret<(2*a[i].product+2*area+(long long)a[i].radium*a[i].radium))
            ret=2*a[i].product+2*area+(long long)a[i].radium*a[i].radium;
    }
    printf("%lld",ret);
    return 0;
}
