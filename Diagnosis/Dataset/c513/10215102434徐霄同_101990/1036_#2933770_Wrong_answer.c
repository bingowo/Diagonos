#include <stdio.h>
#include <stdlib.h>
unsigned long long m(long long a[],long long b[])
{
    long long x,y;
    x=a[0]-b[0];
    y=a[1]-b[1];
    if(x<0)
        x=-x;
    if(y<0)
        y=-y;
    return x+y;
}
int cmp(const void *a,const void *b)
{
    long long *a0=(long long*)a;
    long long *b0=(long long*)b;
    long long c0[2]={0,0};
    if(m(a0,c0)<m(b0,c0))
        return 1;
    else if(m(a0,c0)>m(b0,c0))
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
    long long a[100][2];
    unsigned long long s;
    int i,n;
    scanf("%llu",&n);
    for(i=0;i<n;i++)
        scanf("%lld%lld",&a[i][0],&a[i][1]);
    qsort(a,n,sizeof(a[0]),cmp);
    printf("%llu",m(a[0],a[1]));
    return 0;
}
