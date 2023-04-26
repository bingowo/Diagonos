#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct SSS
{
    long long di;
    long long ce;
    long long all;
}sss;
int cmp(const void*_a,const void*_b)
{
    sss* a=(sss*)_a;
    sss* b=(sss*)_b;
    return((a->ce)>(b->ce)?1:-1);
}
int main()
{
    int n,m,r,h;
    scanf("%d %d",&n,&m);
    sss s[1010];
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&r,&h);
        s[i].di=r*r;
        s[i].ce=2*r*h;
        s[i].all=s[i].di+s[i].ce;
        if(s[i].all>=ans) ans=s[i].all;
    }
    qsort(s,n,sizeof(sss),cmp);
    for(int i=n-1;i>=0 && m>1;i--,m--)
    {
        ans+=s[i].ce;
    }
    printf("%lld",ans);
    return 0;
}

