#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int r;
    int h;
    long long prdt;
}cylinder;

int cmp(const void*a1,const void*b1)
{
    cylinder* a=(cylinder*)a1;
    cylinder* b=(cylinder*)b1;
    if(a->prdt>b->prdt) return -1;
    else return 1;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    cylinder a[1000];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&a[i].r,&a[i].h);
        a[i].prdt=(long long)a[i].r*a[i].h;
    }
    long long ret=0;
    for(int i=0;i<n;i++)
    {
        cylinder a_[1000];
        int k=0;
        for(int j=0;j<n;j++)
        {
            if(j!=i&&a[j].r<=a[i].r) a_[k++]=a[j];
        }
        qsort(a_,k,sizeof(a_[0]),cmp);
        long long ar=0;
        if(k!=0&&k>=m-1)
        {
            for(int cnt=0;cnt<m-1;cnt++)
                ar+=a_[cnt].prdt;
        }
        if(ret<(2*a[i].prdt+ar*2+(long long)a[i].r*a[i].r))
            ret=2*a[i].prdt+ar*2+(long long)a[i].r*a[i].r;
    }
    printf("%lld",ret);
    return 0;
}
