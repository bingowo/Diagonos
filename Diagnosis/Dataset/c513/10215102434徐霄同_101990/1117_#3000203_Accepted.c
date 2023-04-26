#include <stdio.h>
#include <stdlib.h>
long long f(long long x,long long y,long long x0,long long y0)
{
    long long a,b;
    a=labs(x-x0);
    b=labs(y-y0);
    if(a>b)
        return a;
    else
        return b;
}
int cmp(const void *a,const void *b)
{
    long long *a0=(long long*)a;
    long long *b0=(long long*)b;
    if(a0[2]>b0[2])
        return 1;
    else if(a0[2]<b0[2])
        return -1;
    else if(a0[0]>b0[0])
        return 1;
    else if(a0[0]<b0[0])
        return -1;
    else if(a0[1]>b0[1])
        return 1;
    else
        return -1;
}
int main()
{
    long long xy[1000000][3];
    long long x0,y0,i,n;
    scanf("%lld%lld",&x0,&y0);
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld%lld",&xy[i][0],&xy[i][1]);
        xy[i][2]=f(xy[i][0],xy[i][1],x0,y0);
    }
    qsort(xy,n,sizeof(xy[0]),cmp);
    printf("%lld\n",xy[0][2]);
    printf("%lld %lld\n",xy[0][0],xy[0][1]);
    return 0;
}
