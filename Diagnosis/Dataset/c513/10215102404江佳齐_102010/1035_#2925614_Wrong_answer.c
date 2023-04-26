#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct SSS
{
    long long d;
    long long ce;
}s[1010];
int cmp(const void* p,const void* q)
{
    struct SSS a,b;
    a=*((struct SSS*)p);
    b=*((struct SSS*)q);
    return((a.ce)>(b.ce)?-1:1);
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    long long r,h;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&r,&h);
        s[i].d=r*r;
        s[i].ce=2*r*h;
    }
    qsort(s,n,sizeof(s[0]),cmp);
    long long max=0;long long ans=0;int cnt=0;
    for(int i=0;i<n;i++)
    {
        ans=s[i].ce+s[i].d;
        cnt=0;
        for(int j=0;j<n;j++)
        {
            if(cnt==m-1) break;
            if(j==i) continue;
            if(s[j].d<=s[i].d)
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
