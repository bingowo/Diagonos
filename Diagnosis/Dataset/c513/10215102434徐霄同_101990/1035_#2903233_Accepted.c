#include <stdio.h>
#include <stdlib.h>
typedef struct{
    long long r;
    long long h;
    long long ds;
    long long cs;
}yz;
int cmp1(const void *a, const void *b)
{
    yz *a0=(yz*)a;
    yz *b0=(yz*)b;
    if(b0->ds>a0->ds)
        return 1;
    else
        return -1;
}
int cmp2(const void *a, const void *b)
{
    yz *a0=(yz*)a;
    yz *b0=(yz*)b;
    if(b0->cs>a0->cs)
        return 1;
    else
        return -1;
}
int main()
{
    yz a[1000],b[1000];
    int n,m,i,j,k;
    long long s,sm;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d%d",&a[i].r,&a[i].h);
        a[i].ds=a[i].r*a[i].r;
        a[i].cs=a[i].h*2*a[i].r;
    }
    qsort(a,n,sizeof(a[0]),cmp1);
    sm=0;
    for(i=0;i<n-m+1;i++){
        s=a[i].ds+a[i].cs;
        k=0;
        for(j=i+1;j<n;j++){
            b[k]=a[j];
            k++;
        }
        qsort(b,k,sizeof(b[0]),cmp2);
        for(j=0;j<m-1;j++)
            s=s+b[j].cs;
        if(s>sm)
            sm=s;
    }
    printf("%lld",sm);
    return 0;
}
