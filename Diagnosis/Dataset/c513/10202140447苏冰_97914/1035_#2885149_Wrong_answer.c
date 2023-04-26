#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct SSS
{
    long long di;
    long long ce;
}sss;
int cmp(const void*_a,const void*_b)
{
    sss* a=(sss*)_a;
    sss* b=(sss*)_b;
    return((a->ce)>(b->ce)?1:-1);
}
int main()
{
    int n,m,r,h,x=0;
    scanf("%d %d",&n,&m);
    sss s[1010];
    long long ma=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&r,&h);
        s[i].di=r*r;
        s[i].ce=2*r*h;
        if(s[i].di>=ma)
        {
            ma=s[i].di;x=i;
        }
    }
    long long ans=ma;
    qsort(s,n,sizeof(sss),cmp);
    for(int i=n-1;i>=0 && i!=x && m>0;i--,m--)
    {
        ans+=s[i].ce;
    }
    printf("%lld",ans);
    return 0;
}
