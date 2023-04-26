#include <stdio.h>
#include <stdlib.h>

struct cylinder{
    int r,h;
    long long area;
};

int cmp(const void *pa,const void *pb){
    struct cylinder *a=(struct cylinder*)pa;
    struct cylinder *b=(struct cylinder*)pb;
    if(a->area > b->area) return -1;
    else return 1;
}

int main()
{
    int n=0; int m=0;
    scanf("%d %d",&n,&m);
    struct cylinder a[1000];
    for(int i=0;i<n;i++){
        scanf("%d %d",&a[i].r,&a[i].h);
        a[i].area= (long long)a[i].r * a[i].h;
    }

    long long result=0;
    for(int i=0;i<n;i++){
        struct cylinder ax[1000];
        int k=0;
        for(int j=0;j<n;j++){
            if(j!=i && a[j].r<=a[i].r) ax[k++]=a[j];
        }
        qsort(ax,k,sizeof(ax[0]),cmp);
        long long s=0;
        if(k!=0 && k>=m-1){
            for(int cnt=0;cnt<m-1;cnt++){
                s += ax[cnt].area;
            }
        }
        if(result<(2*a[i].area + s*2 + (long long)a[i].r*a[i].r))
            result=(2*a[i].area + s*2 + (long long)a[i].r*a[i].r);
    }
    printf("%lld",result);
    return 0;
}
