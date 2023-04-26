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
    if((a->di)!=(b->di)) return((a->di)>(b->di)?1:-1);
    else return((a->ce)>(b->ce)?1:-1);
}
int main()
{
    int n,m,r,h;
    scanf("%d %d",&n,&m);
    sss s[1010];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&r,&h);
        s[i].di=r*r;
        s[i].ce=2*r*h;
    }
    long long ans=0;
    qsort(s,n,sizeof(sss),cmp);
    for(int i=n-1;i>=0 && m>1;i--,m--)
    {
        ans+=s[i].ce;
    }
    ans+=s[n-1].di+s[n-1].ce;
    printf("%lld",ans);
    return 0;
}
