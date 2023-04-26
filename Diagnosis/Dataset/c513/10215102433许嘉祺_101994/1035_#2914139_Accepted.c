#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct con{
    long long h;
    long long r;
    long long s;
} zhu[1000];
int cmp(const void*a,const void*b){
    long long  a1=((struct con*)a)->s,b1=((struct con*)b)->s;
    if (b1>a1) return 1;
    else return -1;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++){
        scanf("%lld%lld",&zhu[i].r,&zhu[i].h);
        zhu[i].s=zhu[i].r*zhu[i].h*2;

    }
    qsort(zhu,n,sizeof(zhu[0]),cmp);
    long long maxs=0;
    for (int i=0;i<n;i++)
    {
        int count=0;
        long long maxs1=zhu[i].s+zhu[i].r*zhu[i].r;
        for (int j=0;j<n&&count<m-1;j++)
            if (i!=j&&zhu[i].r>=zhu[j].r) {maxs1+=zhu[j].s;count++;}
        if (maxs1>maxs) maxs=maxs1;
    }
    printf("%lld\n",maxs);
    return 0;
}