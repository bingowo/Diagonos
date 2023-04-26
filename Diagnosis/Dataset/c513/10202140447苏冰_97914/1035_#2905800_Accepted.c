#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct SSS
{
    long long di;
    long long ce;
}sss;
int cmp(const void* p,const void* q)
{
    sss* a=(sss*)p;
    sss* b=(sss*)q;
    return((a->ce)>(b->ce)?-1:1);
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    sss s[1010];
    long long r,h;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&r,&h);
        s[i].di=r*r;
        s[i].ce=2*r*h;
    }
    qsort(s,n,sizeof(sss),cmp);
    long long max=0;long long ans=0;int cnt=0;
    for(int i=0;i<n;i++)
    {
        ans=s[i].ce+s[i].di;
        cnt=0;
        for(int j=0;j<n;j++)
        {
            if(cnt==m-1) break;
            if(j==i) continue;
            if(s[j].di<=s[i].di)
            {
                ans+=s[j].ce;
                cnt++;
            }
        }
        if(ans>=max) max=ans;
    }
    printf("%lld",max);
    return 0;
}
